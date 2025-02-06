# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 16:51:47 by vblanc            #+#    #+#              #
#    Updated: 2025/02/06 08:09:53 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra
MLXFLAGS := -lXext -lX11 -lm -lpthread

SRCDIR := ./srcs
OBJDIR := ./objs

SRCS := draw.c hooks.c init.c main.c print_info.c print_info_utils.c
SRCS := $(addprefix $(SRCDIR)/, $(SRCS))
OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

INCLUDES := -I./includes

LIBFT := ./includes/libft/libft.a
MLX := ./includes/minilibx-linux/libmlx.a

NAME := fractol
RM := rm -rf

#TODO: handle minilibx compilation ?

all: libft mlx $(NAME)

libft:
	@make -C includes/libft

mlx:
	@make -C includes/minilibx-linux

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C includes/libft clean
	@make -C includes/minilibx-linux clean
	$(RM) $(OBJDIR)

fclean:
	@make -C includes/libft fclean
	@make -C includes/minilibx-linux clean
	$(RM) $(OBJDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re