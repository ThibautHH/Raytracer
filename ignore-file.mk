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

IGNORED_OBJS			+=	$($(NAME)_MAIN_OBJ)
IGNORED_OBJS			+=	$($(NAME)_OBJS)
IGNORED_OBJS			+=	$($($(NAME)_TESTS)_OBJS)

IGNORED_PCHS			+=	$($(NAME)_OBJS:$(OBJ_EXT)=$(PCH_EXT))
IGNORED_PCHS			+=	$($($(NAME)_TESTS)_OBJS:$(OBJ_EXT)=$(PCH_EXT))

IGNORED_DEPS			+=	$($(NAME)_MAIN_DEP)
IGNORED_DEPS			+=	$($(NAME)_DEPS)
IGNORED_DEPS			+=	$($($(NAME)_TESTS)_DEPS)

IGNORED_BINS			+=	$($(NAME)_TARGET)
IGNORED_BINS			+=	$($(NAME)_TESTS)

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
$(IGNORED_OBJS:=$(nl))
# Ignore precomiled headers
$(IGNORED_PCHS:=$(nl))
# Ignore dependency files
$(IGNORED_DEPS:=$(nl))
# Ignore binary files
$(IGNORED_BINS:=$(nl))
# Ignore logs and reports
*.gcda
*.gcno
vgcore.*

# Ignore coding-style logs
$(CODING_STYLE_LOG)

# Ignore temporary files
a.out
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
