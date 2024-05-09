##
## EPITECH PROJECT, 2024
## Raytracer
## File description:
## Tests Makefile
##

TESTS_DIR				:=	tests/
$(NAME)_TESTS			:=	$(NAME)_tests

$($(NAME)_TESTS)_SRCS	:=	$(shell find $(TESTS_DIR) -type f				\
							-name '*$(SRC_EXT)' ! -name ".*" 2>/dev/null)

$($(NAME)_TESTS)_OBJS	:=													\
	$($($(NAME)_TESTS)_SRCS:$(SRC_DIR)%$(SRC_EXT)=$(OBJ_DIR)%$(OBJ_EXT))

$($(NAME)_TESTS)_DEPS	:=	$($($(NAME)_TESTS)_OBJS:$(OBJ_EXT)=$(DEP_EXT))

-include  $($($(NAME)_TESTS)_DEPS)

#$(NAME)_TEST_SCRIPT	:=	$(TESTS_DIR)test-arguments
ifdef $(NAME)_LINK
$($(NAME)_TESTS)_REQS	:=	$($(NAME)_OBJS)
else
$($(NAME)_TESTS)_REQS	:=	$($(NAME)_TARGET)
$($(NAME)_TESTS):		LIBS += $(NAME)
endif
$($(NAME)_TESTS):		LIBS += criterion
$($(NAME)_TESTS):		GCCFLAGS += --coverage
$($(NAME)_TESTS):		$($($(NAME)_TESTS)_REQS) $($($(NAME)_TESTS)_OBJS)
	@-echo 'Linking $@ binary...'
ifdef $(NAME)_LINK
	@$(LINKER) $(GCCFLAGS) -o $@ $^	$(LDLIBS) $(LDFLAGS)
else
	@$(LINKER) $(GCCFLAGS) -o $@ $(filter-out $<,$^) $(LDLIBS) $(LDFLAGS)
endif

$($($(NAME)_TESTS)_OBJS):	GCCFLAGS := $(filter-out --coverage,$(GCCFLAGS))

TESTFLAGS				+=	$(TEST_SUITES:%=--filter '%/*')

tests:					$(IGNORE_FILE) $($(NAME)_TESTS)
	@-echo 'Running test script...' >&2
	@$($(NAME)_TEST_SCRIPT)
	@-echo 'Running tests...' >&2
	@./$($(NAME)_TESTS) --verbose $(TESTFLAGS)

tests_run:				TESTFLAGS += --always-succeed
tests_run:				$($(NAME)_TESTS)
	@./$($(NAME)_TESTS) --verbose $(TESTFLAGS)
	@-find -type f \( -name '*.gcno' -o -name '*.gcda' \) -exec mv -- {} . \;

tests-debug:			GCCFLAGS += -g
tests-debug:			$($(NAME)_TESTS)
	@-echo 'Debugging tests...' >&2
	@-valgrind --trace-children=yes	./$($(NAME)_TESTS) --verbose $(TESTFLAGS)

coverage:				tests
	@-echo 'Generating coverage report...' >&2
	@gcovr --exclude $(TESTS_DIR) --txt-metric line
	@gcovr --exclude $(TESTS_DIR) --txt-metric decision

tests-re:				fclean tests

.PHONY:					tests coverage tests-debug tests-re tests_run
