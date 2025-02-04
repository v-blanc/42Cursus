# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 16:51:47 by vblanc            #+#    #+#              #
#    Updated: 2025/02/04 23:03:28 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra
MLXFLAGS := -lXext -lX11 -lm

SRCDIR := ./srcs
OBJDIR := ./objs

SRCS := complex.c main.c
SRCS := $(addprefix $(SRCDIR)/, $(SRCS))
OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

INCLUDES := -I./includes -I./libft -I./minilibx-linux

LIBFT := ./libft/libft.a
MLX := ./minilibx-linux/libmlx.a

NAME := fractol
RM := rm -rf

#TODO: handle minilibx compilation ?

all: libft $(NAME)

libft:
	@make -C libft

mlx:
	@make -C minilibx-linux

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C libft clean
	$(RM) $(OBJDIR)

fclean:
	@make -C libft fclean
	$(RM) $(OBJDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re