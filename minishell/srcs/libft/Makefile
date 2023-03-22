# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 09:07:34 by alrusso           #+#    #+#              #
#    Updated: 2022/09/29 09:07:50 by alrusso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror

NAME := libft.a

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
B_SRCS := ft_lstadd_back.c ft_lstadd_front.c \
		ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c \
		ft_lstnew.c ft_lstsize.c
B_OBJS := ${B_SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

bonus: $(NAME) $(B_OBJS)
	@ar rcs $(NAME) $(B_OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
