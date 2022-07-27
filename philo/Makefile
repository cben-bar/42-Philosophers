# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 19:02:43 by cben-bar          #+#    #+#              #
#    Updated: 2022/07/25 16:31:00 by cben-bar         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := philo

LST_INCS := philo.h

LST_SRCS := main.c				\
			parsing.c			\
			ft_atoi.c			\
			init.c				\
			lst.c				\
			ft_go.c				\
			ft_actions.c		\
			utils.c				\

LST_OBJS := $(LST_SRCS:.c=.o)

CC := gcc

CFLAGS := -g -Wall -Wextra -Werror

RM := rm -rf

DIR_SRCS := srcs
DIR_OBJS := .objects
DIR_INCS := includes

SRCS := $(addprefix $(DIR_SRCS)/, $(LST_SRCS))
OBJS := $(addprefix $(DIR_OBJS)/, $(LST_OBJS))
INCS := $(addprefix $(DIR_INCS)/, $(LST_INCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(INCS)
	mkdir -p $(DIR_OBJS)
	$(CC) $(CFLAGS) -I $(DIR_INCS) -c $< -o $@

clean:
	$(RM) $(DIR_OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
