##
## EPITECH PROJECT, 2024
## Raytracer
## File description:
## Makefile
##

.SECONDEXPANSION:
SRC_DIR					:=	src/
OBJ_DIR					:=	obj/
MODULES_DIR				:=	plugins/
MOD_DIR					=	$(dir $(lastword $(MAKEFILE_LIST)))

LANG					:=	cpp

ifeq ($(LANG),cpp)
SRC_EXT					:=	.cpp
HDR_EXT					:=	.hpp
else ifeq ($(LANG), c)
SRC_EXT					:=	.c
HDR_EXT					:=	.h
endif
OBJ_EXT					:=	.o
DEP_EXT					:=	.d
PCH_EXT					:=	$(HDR_EXT).gch

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
MODULE_TARGET			=	$(MODULES_DIR)$(NAME)_$(MODULE_NAME).so

$(NAME)_DISPLAY			:=	Raytracer

$(NAME)_MAIN_SRC		:=	$(SRC_DIR)main$(SRC_EXT)
$(NAME)_SRCS			:=	$(addprefix $(SRC_DIR), $(addsuffix $(SRC_EXT),	\
								Termination									\
								$(addprefix Core/,							\
									Processor Vector)						\
								$(addprefix DynamicLibrary/,				\
									DLLibrary)								\
								$(addprefix Modules/,						\
									Module)									\
							))

CODING_STYLE_LOG		:=	coding-style-reports.log
CODING_STYLE_IMAGE		:=	ghcr.io/epitech/coding-style-checker:latest

$(NAME)_MAIN_OBJ		:=													\
	$($(NAME)_MAIN_SRC:$(SRC_DIR)%$(SRC_EXT)=$(OBJ_DIR)%$(OBJ_EXT))
$(NAME)_OBJS			:=													\
	$($(NAME)_SRCS:$(SRC_DIR)%$(SRC_EXT)=$(OBJ_DIR)%$(OBJ_EXT))

$(NAME)_MAIN_DEP		:=	$($(NAME)_MAIN_OBJ:$(OBJ_EXT)=$(DEP_EXT))
$(NAME)_DEPS			:=	$($(NAME)_OBJS:$(OBJ_EXT)=$(DEP_EXT))

LIBS					:=
ifndef $(NAME)_LINK
LIB_DIRS				+=	$(dir $($(NAME)_TARGET))
endif
RM						:=	rm -f
AR						:=	ar
ARFLAGS					:=	rcs
CXX						:=	g++
CC						:=	gcc
DOCKER					:=	[ -r /var/run/docker.sock ] &&	\
							[ -w /var/run/docker.sock ]
DOCKER					:=	cmd="$$(which docker)"	\
							&& if ! ($(DOCKER));	\
							then cmd="sudo $${cmd}";\
							fi; echo "$${cmd}"
DOCKER					:=	$(shell $(DOCKER))
HDR						=	$(findstring $(SRC_DIR)$*$(HDR_EXT),$^)
PCH						=	$(HDR:$(SRC_DIR)%$(HDR_EXT)=$(OBJ_DIR)%$(PCH_EXT))
PCHFLAGS				=	$(patsubst %,-iquote %,$(dir $(PCH)))			\
							$(patsubst %,-include %,$(notdir $(HDR)))
GCCFLAGS				=	$(PCHFLAGS) $(PROJECT_INCLUDE_DIRS:%=-iquote %)	\
							-W -Wall -Wextra -Wduplicated-cond				\
							-Wduplicated-branches -Wlogical-op				\
							-Wnull-dereference -Wdouble-promotion -Wshadow	\
							-Wformat=2 -Wpedantic -Winvalid-pch				\
							-Wl,--no-undefined -O3							\
							$(if $($(NAME)_SHARED),-fPIC,)
CXXFLAGS				=	$(GCCFLAGS) -std=c++20
CFLAGS					=	$(GCCFLAGS) -std=c99
ifeq ($(LANG),cpp)
COMPILER				:=	$(CXX)
LINKER					:=	$(CXX)
GCC						:=	$(CXX)
FLAGS					=	$(CXXFLAGS)
else ifeq ($(LANG), c)
COMPILER				:=	$(CC)
LINKER					:=	$(CC)
GCC						:=	$(CC)
FLAGS					=	$(CFLAGS)
endif
LDLIBS					=	$(LIBS:%=-l%)
LDFLAGS					=	$(LIB_DIRS:%=-L%)

all:					$($(NAME)_TARGET) modules
	@:

debug:					GCCFLAGS += -g -Og
debug:					all

$($(NAME)_TARGET):		$($(NAME)_OBJS)
ifdef $(NAME)_LINK
$($(NAME)_TARGET):		$($(NAME)_MAIN_OBJ)
	@-echo 'Linking $@ binary...'
	@$(LINKER) $(FLAGS) -o $@ $^ $(LDLIBS) $(LDFLAGS)
else
$($(NAME)_TARGET):
	@-echo 'Archiving $(@:lib%$(LIB_EXT)=%) objects into $@...'
	@$(AR) $(ARFLAGS) $@ $^

main: 					LIBS += $(NAME)
main:					$($(NAME)_MAIN_OBJ) $($(NAME)_TARGET)	\
						$(IGNORE_FILE)
	@-echo 'Linking $(NAME) binary...'
	@$(COMPILER) $(FLAGS) -o $(NAME) $< $(LDLIBS) $(LDFLAGS)

main_debug:				GCCFLAGS += -g
main_debug:				main
	@:

.PHONY:					main main_debug
endif

-include $($(NAME)_MAIN_DEP) $($(NAME)_DEPS)

modules:
	@:

$(MODULES_DIR)$(NAME)_%.so:	$$($$*_OBJS)
	@-echo 'Linking $@ module...'
	@mkdir -p $(dir $@)
	@$(GCC) -shared -fPIC $(FLAGS) -o $@ $^ $(LDLIBS) $(LDFLAGS)

SRC_BASE				=	$(if $(filter $(TESTS_DIR)%,$*),,$(SRC_DIR))

$(OBJ_DIR)%$(DEP_EXT):	$$(SRC_BASE)%$(SRC_EXT)
	@-echo 'Generating dependencies for $<...' >&2
	@mkdir -p $(dir $@)
	@$(GCC) $< -MM -MF $@ -MT $(@:$(DEP_EXT)=$(OBJ_EXT)) $(GCCFLAGS)

$(OBJ_DIR)%$(PCH_EXT):	$$(SRC_BASE)%$(HDR_EXT)
	@-echo 'Precompiling $<...' >&2
	@mkdir -p $(dir $@)
	@$(COMPILER) -c $(filter-out $(PCHFLAGS),$(FLAGS)) $< -o $@

$(OBJ_DIR)%$(OBJ_EXT):	$$(SRC_BASE)%$(SRC_EXT) $$(PCH)
	@-echo 'Compiling $<...' >&2
	@mkdir -p $(dir $@)
	@$(COMPILER) -c $(FLAGS) $< -o $@

include tests.mk ignore-file.mk

-include $(foreach component,. Configuration Lights Primitives Materials,	\
	$(wildcard $(SRC_DIR)$(component)/Modules/*/module.mk))

docs:					$(IGNORE_FILE)
	@-echo 'Generating documentation...' >&2
	@doxygen

coding-style:			fclean
	@-echo 'Checking coding style...' >&2
	@$(DOCKER) run --rm -v .:/mnt $(CODING_STYLE_IMAGE) /mnt /mnt

clean:
	@-echo 'Deleting build directory...' >&2
	@$(RM) -r $(OBJ_DIR)
	@-echo 'Cleaning up unecessary files...' >&2
	@-find \( -name '*~' -o -name 'vgcore.*' -o -name '*.gc*'	\
	-o -name 'a.out' -o -name '$(CODING_STYLE_LOG)' \) -delete

fclean:					clean
	@-echo 'Deleting $($(NAME)_TARGET)...' >&2
	@$(RM) $($(NAME)_TARGET)
	@-echo 'Deleting $(MODULES_DIR)...' >&2
	@$(RM) -r $(MODULES_DIR)
	@-echo 'Deleting $($(NAME)_TESTS)...' >&2
	@$(RM) $($(NAME)_TESTS)

re:						fclean all

.PHONY:					all modules debug clean fclean re docs coding-style
