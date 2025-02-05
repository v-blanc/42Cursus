# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 17:58:55 by vblanc            #+#    #+#              #
#    Updated: 2025/02/05 11:40:29 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra

SRCS_DIR := ./srcs
SRCS_SERVER := $(SRCS_DIR)/server.c
SRCS_CLIENT := $(SRCS_DIR)/client.c
SRCS_UTILS := $(SRCS_DIR)/utils.c

OBJS_DIR := ./objs
OBJS_SERVER := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS_SERVER:.c=.o)))
OBJS_CLIENT := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS_CLIENT:.c=.o)))
OBJS_UTILS := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS_UTILS:.c=.o)))

LIBFT := ./includes/libft/libft.a

NAME := minitalk
NAME_SERVER := server
NAME_CLIENT := client
RM := rm -rf

all: $(NAME)

libft:
	@make -C includes/libft

$(NAME): $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(OBJS_UTILS)
	@make libft
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

$(NAME_CLIENT): $(OBJS_CLIENT) $(OBJS_UTILS)
	@make libft
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@make -C includes/libft clean
	$(RM) $(OBJS_DIR)

fclean:
	@make -C includes/libft fclean
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all minitalk clean fclean re