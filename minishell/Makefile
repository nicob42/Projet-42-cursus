# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 09:00:55 by alrusso           #+#    #+#              #
#    Updated: 2022/09/29 09:01:31 by alrusso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Werror -Wextra
LIB := -L/Users/$(USER)/.brew/opt/readline/lib \
	-lreadline

SRC_DIR := srcs
OBJ_DIR := obj
BIN_DIR := .

LIBFT_DIR = srcs/libft/
LIBFT_A = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_A))

NAME := $(BIN_DIR)/minishell

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NONE := '\033[0m'
GREEN := '\033[92m'
GRAY := '\033[90m'
RED := '\033[91m'
CURSIVE := '\033[3m'

all : $(NAME)

$(NAME): $(OBJ) | $(BIN_DIR)
	@echo $(CURSIVE)$(GRAY)" -- Making $(LIBFT_A) --"$(NONE)
	@make -C $(LIBFT_DIR)
	@echo "$(NAME): $(GREEN)$(LIBFT_A) was created !$(NONE)"
	@echo $(CURSIVE)$(GRAY)" -- Making $(NAME) --"$(NONE)
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@ $(DANGER) $(LIB)
	@echo "$(NAME): $(GREEN)$(NAME) was created !$(NONE)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo $(CURSIVE)$(GRAY)" -- Making $(NAME) objects --"$(NONE)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(NAME): $(GREEN)$(NAME) objects was created !$(NONE)"

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
		@echo $(CURSIVE)$(GRAY)" -- Deleting $(LIBFT_A) --"$(NONE)
		@make -C $(LIBFT_DIR) clean
		@echo "$(RED) $(LIBFT_A) objects was deleted !$(NONE)"
		@echo $(CURSIVE)$(GRAY)" -- Deleting objects --"$(NONE)
		rm -f $(NAME) $(OBJ)
		@echo "$(RED) objects was deleted !$(NONE)"

fclean:
		@echo $(CURSIVE)$(GRAY)" -- Deleting $(LIBFT_A) --"$(NONE)
		@make -C $(LIBFT_DIR) fclean
		@echo "$(RED) $(LIBFT_A) was deleted !$(NONE)"
		@echo $(CURSIVE)$(GRAY)" -- Deleting $(NAME) --"$(NONE)
		rm -f $(NAME) $(OBJ)
		@echo "$(RED) $(NAME) was deleted !"$(NONE)

re: fclean all
