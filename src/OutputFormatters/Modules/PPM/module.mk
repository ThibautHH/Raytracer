##
## EPITECH PROJECT, 2024
## Raytracer
## File description:
## PPM module Makefile
##

MODULE_NAME			:=	ppm

$(MODULE_NAME)_SRCS	:=	$(addsuffix $(SRC_EXT),$(addprefix $(MOD_DIR),	\
								OutputFormatter							\
						))

$(MODULE_NAME)_OBJS	:=													\
	$($(MODULE_NAME)_SRCS:$(SRC_DIR)%$(SRC_EXT)=$(OBJ_DIR)%$(OBJ_EXT))

$(MODULE_NAME)_DEPS	:=	$($(MODULE_NAME)_OBJS:$(OBJ_EXT)=$(DEP_EXT))

IGNORED_OBJS		+=	$($(MODULE_NAME)_OBJS)
IGNORED_PCHS		+=	$($(MODULE_NAME)_OBJS:$(OBJ_EXT)=$(PCH_EXT))
IGNORED_DEPS		+=	$($(MODULE_NAME)_DEPS)

IGNORED_BINS		+=	$(MODULE_TARGET)

-include $($(MODULE_NAME)_DEPS)

modules:			$(MODULE_TARGET)

$(MOD_DIR)%$(OBJ_EXT):	GCCFLAGS += -fPIC
