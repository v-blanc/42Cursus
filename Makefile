# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 14:05:41 by vblanc            #+#    #+#              #
#    Updated: 2024/11/19 14:14:42 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra

SRCS_SERVER := server.c
SRCS_CLIENT := client.c

NAME_PROJECT := minitalk
NAME_SERVER := server
NAME_CLIENT := client
RM := rm -rf

all: $(NAME_PROJECT)

$(NAME_PROJECT): $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SRCS_SERVER)
	$(CC) $(CFLAGS) $< -o $@

$(NAME_CLIENT): $(SRCS_CLIENT)
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(NAME_SERVER)
	$(RM) $(NAME_CLIENT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re