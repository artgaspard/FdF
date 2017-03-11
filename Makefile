#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/02/19 16:34:57 by agaspard          #+#    #+#             *#
#*   Updated: 2017/03/11 13:05:55 by agaspard         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fdf
# **************************************************************************** #

# COMPILATION
CC = clang
CCFLAGS = -Wall -Werror -Wextra
LIBFLAGS = -lmlx -framework OpenGL -framework AppKit

# DIRECTORIES
D_SRC = src
D_INC = inc
D_OBJ = obj
D_LIB = libft

# LIBRARIES
F_LIB = libft/libft.a
DF_LIB =  $(addprefix $(D_LIB)/, $(F_LIB))
LDFLAGS = $(addprefix -L, $(D_LIB))
LDLIBS = -lft

# SOURCES
F_SRC =\
	   main.c \
	   make_img.c \
	   parse_map.c \
	   print_fd.c \
	   keys.c \
	   size.c \

# ***************************************************************************** #

# SPECIAL CHARS
LOG_CLEAR               = \033[2K
LOG_UP                  = \033[A
LOG_NOCOLOR             = \033[0m
LOG_BLACK               = \033[1;30m
LOG_RED                 = \033[1;31m
LOG_GREEN               = \033[1;32m
LOG_YELLOW              = \033[1;33m
LOG_BLUE                = \033[1;34m
LOG_VIOLET              = \033[1;35m
LOG_CYAN                = \033[1;36m
LOG_WHITE               = \033[1;37m

# ****************************************************************************** #

.PHONY: make all fclean re

F_OBJ = $(addsuffix .o, $(basename $(F_SRC)))
DF_SRC = $(addprefix $(D_SRC)/, $(F_SRC))
DF_OBJ = $(addprefix $(D_OBJ)/, $(F_OBJ))

RM = /bin/rm -rf

all: $(NAME)
$(D_OBJ)/%.o: $(D_SRC)/%.c $(D_INC)
	@mkdir -p $(D_OBJ) 2> /dev/null || true
	@echo "$(LOG_CYAN)$(NAME)... $(LOG_NOCOLOR)$<"
	@$(CC) $(CCFLAGS) -I $(D_INC) -o $@ -c $<

$(NAME): $(DF_OBJ)
	@make -C $(D_LIB)
	@echo "$(LOG_CYAN)$(NAME)... assembling...$(LOG_NOCOLOR)"
	@$(CC) $(LIBFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "$(LOG_GREEN)$(NAME)... compiled ✓$(LOG_NOCOLOR)"

clean:
	@echo "$(LOG_RED)Deleting fdf's objs ✖$(LOG_NOCOLOR)"
	@$(RM) $(D_OBJ)

fclean: clean
	@echo "$(LOG_RED)Deleting fdf ✖$(LOG_NOCOLOR)"
	@$(RM) $(NAME)

fcleanlib:
	@make fclean -C libft

re: fclean all

