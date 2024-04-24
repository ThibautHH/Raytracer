##
## EPITECH PROJECT, 2024
## Raytracer
## File description:
## Makefile
##

.SECONDEXPANSION:
SRC_DIR					:=	src/
BUILD_DIR				:=	obj/
TESTS_DIR				:=	tests/

CPP						:=	1

ifdef CPP
SRC_EXT					:=	.cpp
HDR_EXT					:=	.hpp
else
SRC_EXT					:=	.c
HDR_EXT					:=	.h
endif
PCH_EXT					:=	.gch

NAME					:=	raytracer
$(NAME)_LINK			:=	1
ifdef $(NAME)_LINK
$(NAME)_TARGET			:=	$(NAME)
else
#$(NAME)_SHARED			:=	1
ifdef $(NAME)_SHARED
LIB_EXT					:=	.so
else
LIB_EXT					:=	.a
endif
$(NAME)_TARGET			:=	$(NAME:%=lib%$(LIB_EXT))
endif
$(NAME)_DISPLAY			:=	Raytracer
$(NAME)_TESTS			:=	$(NAME)_tests

$(NAME)_MAIN_SRC		:=	$(SRC_DIR)main$(SRC_EXT)
$(NAME)_SRCS			:=	$(addprefix $(SRC_DIR), $(addsuffix $(SRC_EXT),	\
								Termination									\
								$(addprefix Core/,							\
									Processor Vector)						\
							))
$($(NAME)_TESTS)_SRCS	:=	$(shell find $(TESTS_DIR) -type f				\
							-name '*$(SRC_EXT)' ! -name ".*" 2>/dev/null)

IGNORE_FILE				:=	.gitignore
IGNORED_FILES			:=	compile_commands.json
ifndef $(NAME)_LINK
IGNORED_FILES			+=  $($(NAME)_MAIN_SRC)
endif
CODING_STYLE_LOG		:=	coding-style-reports.log

$(NAME)_MAIN_OBJ		:=											\
	$($(NAME)_MAIN_SRC:$(SRC_DIR)%$(SRC_EXT)=$(BUILD_DIR)%.o)
$(NAME)_OBJS			:=											\
	$($(NAME)_SRCS:$(SRC_DIR)%$(SRC_EXT)=$(BUILD_DIR)%.o)
$($(NAME)_TESTS)_OBJS	:=											\
	$($($(NAME)_TESTS)_SRCS:$(SRC_DIR)%$(SRC_EXT)=$(BUILD_DIR)%.o)

$(NAME)_MAIN_DEP		:=	$($(NAME)_MAIN_OBJ:.o=.d)
$(NAME)_DEPS			:=	$($(NAME)_OBJS:.o=.d)
$($(NAME)_TESTS)_DEPS	:=	$($($(NAME)_TESTS)_OBJS:.o=.d)

LIBS					:=
ifndef $(NAME)_LINK
LIB_DIRS				+=	$(dir $($(NAME)_TARGET))
endif
HDR						=	$(findstring $(SRC_DIR)$*$(HDR_EXT),$^)
PCH						=											\
	$(HDR:$(SRC_DIR)%$(HDR_EXT)=$(BUILD_DIR)%$(HDR_EXT)$(PCH_EXT))
RM						:=	rm -r
AR						:=	ar
ARFLAGS					:=	rcs
CXX						:=	g++
GCC						:=	gcc
CC						:=	$(GCC)
PCHFLAGS				=	$(patsubst %,-iquote %,$(dir $(PCH)))			\
							$(patsubst %,-include %,$(notdir $(HDR)))
GCCFLAGS				=	$(PCHFLAGS) $(PROJECT_INCLUDE_DIRS:%=-iquote %)	\
							-W -Wall -Wextra -Wduplicated-cond				\
							-Wduplicated-branches -Wlogical-op				\
							-Wnull-dereference -Wdouble-promotion -Wshadow	\
							-Wformat=2 -Wpedantic -Winvalid-pch				\
							-Wl,--no-undefined								\
							-fno-gnu-unique $(if $($(NAME)_SHARED),,-fPIC)
CXXFLAGS				=	$(GCCFLAGS) -std=c++20
CFLAGS					=	$(GCCFLAGS) -std=c99
ifdef CPP
COMPILER				:=	$(CXX)
LINKER					:=	$(CXX)
FLAGS					:=	$(CXXFLAGS)
else
COMPILER				:=	$(CC)
LINKER					:=	$(CC)
FLAGS					:=	$(CFLAGS)
endif
LDLIBS					=	$(LIBS:%=-l%)
LDFLAGS					=	$(LIB_DIRS:%=-L%)

all:						$(IGNORE_FILE) $($(NAME)_TARGET)
	@:

debug:						GCCFLAGS += -g
debug:						all

define nl


endef
define $(IGNORE_FILE)_CONTENT
##
## EPITECH PROJECT, $(shell date +%Y)
## $($(NAME)_DISPLAY)
## File description:
## $(IGNORE_FILE)
##

# Ignore object files
$($(NAME)_MAIN_OBJ)
$($(NAME)_OBJS:%=%$(nl))
$($($(NAME)_TESTS)_OBJS:%=%$(nl))
# Ignore dependency files
$($(NAME)_MAIN_DEP)
$($(NAME)_DEPS:%=%$(nl))
$($($(NAME)_TESTS)_DEPS:%=%$(nl))
# Ignore binary files
$($(NAME)_TARGET)
$($(NAME)_TESTS)
a.out

# Ignore logs and reports
*.gc*
vgcore.*

# Ignore coding-style logs
$(CODING_STYLE_LOG)

# Ignore temporary files
*tmp*
*~
\#*#
.#*
*.swp

# Miscellanous
$(IGNORED_FILES:%=%$(nl))
endef

$(IGNORE_FILE):
ifeq ($(wildcard $(IGNORE_FILE)),)
	@-echo 'Generating $@ file...' >&2
else
	@-echo 'Updating $@ file...' >&2
endif
	@echo -ne "$(subst $(nl),\n,$($@_CONTENT))" > $@
	@sed -i -E 's/^ //g' $@

$($(NAME)_TARGET):			$($(NAME)_OBJS)
ifdef $(NAME)_LINK
$($(NAME)_TARGET):			$($(NAME)_MAIN_OBJ)
	@-echo 'Linking $@ binary...'
	@$(LINKER) $(FLAGS) -o $@ $^ $(LDLIBS) $(LDFLAGS)
else
$($(NAME)_TARGET):
	@-echo 'Archiving $(@:lib%$(LIB_EXT)=%) objects into $@...'
	@$(AR) $(ARFLAGS) $@ $^

main_debug:					GCCFLAGS += -g
main_debug:					main
	@:

main: 						LIBS += $(NAME)
main:						$($(NAME)_MAIN_OBJ) $($(NAME)_TARGET)	\
							$(IGNORE_FILE)
	@-echo 'Linking $(NAME) binary...'
	@$(COMPILER) $(FLAGS) -o $(NAME) $< $(LDLIBS) $(LDFLAGS)

.PHONY:						main main_debug
endif

-include $($(NAME)_MAIN_DEP) $($(NAME)_DEPS) $($($(NAME)_TESTS)_DEPS)

$(BUILD_DIR)%.d:			$(SRC_DIR)%$(SRC_EXT)
	@-echo 'Generating dependencies for $<...' >&2
	@mkdir -p $(dir $@)
	@$(GCC) $< -MM -MF $@ -MT $(@:.d=.o) $(GCCFLAGS)

$(BUILD_DIR)%$(HDR_EXT)$(PCH_EXT):		$(SRC_DIR)%$(HDR_EXT)
	@-echo 'Precompiling $<...' >&2
	@mkdir -p $(dir $@)
	@$(COMPILER) -c $(filter-out $(PCHFLAGS),$(FLAGS)) $< -o $@

$(BUILD_DIR)%.o:			$(SRC_DIR)%$(SRC_EXT) $$(PCH)
	@-echo 'Compiling $<...' >&2
	@mkdir -p $(dir $@)
	@$(COMPILER) -c $(FLAGS) $< -o $@

docs:						$(IGNORE_FILE)
	@-echo 'Generating documentation...' >&2
	@doxygen doc/Doxyfile

coding-style:				fclean
	@-echo 'Checking coding style...' >&2

clean:
	@-echo 'Deleting build directory...' >&2
	@$(RM) -f $(BUILD_DIR)
	@-echo 'Cleaning up unecessary files...' >&2
	@-find \( -name '*~' -o -name 'vgcore.*' -o -name '*.gc*'	\
	-o -name 'a.out' -o -name '$(CODING_STYLE_LOG)' \) -delete

fclean:						clean
	@-echo 'Deleting $($(NAME)_TARGET)...' >&2
	@$(RM) -f $($(NAME)_TARGET)
	@-echo 'Deleting $($(NAME)_TESTS)...' >&2
	@$(RM) -f $($(NAME)_TESTS)

re:							fclean all

re_tests:					fclean tests_run

.PHONY:						all debug tests_run tests_debug		\
							coverage clean fclean re re_tests	\
							docs coding-style $(IGNORE_FILE)
