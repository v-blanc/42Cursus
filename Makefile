# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 14:05:41 by vblanc            #+#    #+#              #
#    Updated: 2024/12/04 17:11:43 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra

SRCS_SERVER := server.c
SRCS_CLIENT := client.c
SRCS_UTILS := utils.c

OBJ_UTILS := $(SRCS_UTILS:.c=.o)

NAME := minitalk
NAME_SERVER := server
NAME_CLIENT := client
RM := rm -rf

all: $(NAME)

$(NAME): $(OBJ)

	$(CC) $(CFLAGS) $(SRCS_SERVER) $(SRCS_UTILS) -o $(NAME_SERVER)
	$(CC) $(CFLAGS) $(SRCS_CLIENT) $(SRCS_UTILS) -o $(NAME_CLIENT)

# $(NAME): $(NAME_UTILS) $(NAME_SERVER) $(NAME_CLIENT)

# $(NAME_UTILS): $(SRCS_UTILS)
# 	$(CC) $(CFLAGS) -c $(SRCS_UTILS) -o $(OBJ_UTILS)

# $(NAME_SERVER): $(SRCS_SERVER)
# 	$(CC) $(CFLAGS) $< $(OBJ_UTILS) -o $@

# $(NAME_CLIENT): $(SRCS_CLIENT)
# 	$(CC) $(CFLAGS) $< $(OBJ_UTILS) -o $@

clean:
	$(RM) $(NAME_SERVER)
	$(RM) $(NAME_CLIENT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re