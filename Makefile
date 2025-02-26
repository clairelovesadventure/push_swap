# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shutan <shutan@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 11:06:45 by shutan            #+#    #+#              #
#    Updated: 2025/02/26 18:17:00 by shutan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
INC_DIR = includes

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/stack_init.c \
       $(SRC_DIR)/stack_operations.c \
       $(SRC_DIR)/stack_operations2.c \
       $(SRC_DIR)/stack_operations3.c \
       $(SRC_DIR)/stack_operations4.c \
       $(SRC_DIR)/stack_utils.c \
       $(SRC_DIR)/stack_utils2.c \
       $(SRC_DIR)/stack_utils3.c \
       $(SRC_DIR)/sort_small.c \
       $(SRC_DIR)/sort_large.c \
       $(SRC_DIR)/cost_calculation.c \
       $(SRC_DIR)/cost_calculation2.c \
       $(SRC_DIR)/error_control.c \
       $(SRC_DIR)/parse_utils.c \
       $(SRC_DIR)/split_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 