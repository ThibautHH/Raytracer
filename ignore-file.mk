##
## EPITECH PROJECT, 2024
## Raytracer
## File description:
## Ignore file Makefile
##

IGNORE_FILE				:=	.gitignore
IGNORED_FILES			:=	compile_commands.json
ifndef $(NAME)_LINK
IGNORED_FILES			+=  $($(NAME)_MAIN_SRC)
endif

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
$($(NAME)_OBJS:=$(nl))
$($($(NAME)_TESTS)_OBJS:=$(nl))
# Ignore precomiled headers
$($(NAME)_OBJS:$(OBJ_EXT)=$(PCH_EXT)$(nl))
$($($(NAME)_TESTS)_OBJS:$(OBJ_EXT)=$(PCH_EXT)$(nl))
# Ignore dependency files
$($(NAME)_MAIN_DEP)
$($(NAME)_DEPS:=$(nl))
$($($(NAME)_TESTS)_DEPS:=$(nl))
# Ignore binary files
$($(NAME)_TARGET)
$($(NAME)_TESTS)
a.out

# Ignore logs and reports
*.gcda
*.gcno
vgcore.*

# Ignore coding-style logs
$(CODING_STYLE_LOG)

# Ignore temporary files
*tmp*
*~
\#*#
.#*

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

all:			$(IGNORE_FILE)

.PHONY:			$(IGNORE_FILE)
