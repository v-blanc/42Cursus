# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 17:58:55 by vblanc            #+#    #+#              #
#    Updated: 2025/02/01 18:12:40 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra

SRCS_DIR := srcs
SRCS_SERVER := $(SRCS_DIR)/server.c
SRCS_CLIENT := $(SRCS_DIR)/client.c
SRCS_UTILS := $(SRCS_DIR)/utils.c

OBJS_DIR := objs
OBJS_SERVER := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS_SERVER:.c=.o)))
OBJS_CLIENT := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS_CLIENT:.c=.o)))
OBJS_UTILS := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS_UTILS:.c=.o)))

NAME := minitalk
NAME_SERVER := server
NAME_CLIENT := client
RM := rm -rf

all: $(NAME)

$(NAME): $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(OBJS_UTILS)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_CLIENT): $(OBJS_CLIENT) $(OBJS_UTILS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all minitalk clean fclean re