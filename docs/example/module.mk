##
## EPITECH PROJECT, 2024
## Raytracer
## File description:
## Example module Makefile
##

MODULE_NAME			:=	example

$(MODULE_NAME)_SRCS	:=	$(addprefix $(MOD_DIR), $(addsuffix $(SRC_EXT),	\
								Example									\
						))

$(MODULE_NAME)_OBJS	:=													\
	$($(MODULE_NAME)_SRCS:$(SRC_DIR)%$(SRC_EXT)=$(OBJ_DIR)%$(OBJ_EXT))

$(MODULE_NAME)_DEPS	:=	$($(MODULE_NAME)_OBJS:$(OBJ_EXT)=$(DEP_EXT))

IGNORED_OBJS		+=	$($(MODULE_NAME)_OBJS)
IGNORED_PCHS		+=	$($(MODULE_NAME)_OBJS:$(OBJ_EXT)=$(PCH_EXT))
IGNORED_DEPS		+=	$($(MODULE_NAME)_DEPS)

# Link against the 'libexample' library
#$(MODULE_TARGET):	LIBS += example

IGNORED_BINS		+=	$(MODULE_TARGET)

-include $($(MODULE_NAME)_DEPS)

modules:			$(MODULE_TARGET)

$(MOD_DIR)%$(OBJ_EXT):	GCCFLAGS += -fPIC
