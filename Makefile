# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 16:51:47 by vblanc            #+#    #+#              #
#    Updated: 2025/02/06 18:36:42 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra
MLXFLAGS := -lXext -lX11 -lm -lpthread

SRCDIR := ./srcs
OBJDIR := ./objs

SRCS := draw.c draw_multithreads.c hooks.c init.c main.c put_image.c utils.c
SRCS := $(addprefix $(SRCDIR)/, $(SRCS))
OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

INCLUDES := -I./includes

LIBFT := ./includes/libft/libft.a
MLX := ./includes/minilibx-linux/libmlx.a

NAME := fractol
RM := rm -rf


all: $(NAME)

libft:
	@make -C includes/libft;

mlx:
	@make -C includes/minilibx-linux;

$(NAME): $(OBJS)
	@make -C includes/libft;
	@make -C includes/minilibx-linux;
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@if [ expr $(ls includes/libft | wc -l) ]\
		|| [ expr $(ls includes/minilibx-linux | wc -l) ]; then\
		git submodule init && git submodule update;\
	fi
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

.PHONY: all libft mlx clean fclean re