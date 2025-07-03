# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 16:51:47 by vblanc            #+#    #+#              #
#    Updated: 2025/04/23 20:40:45 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra
MLXFLAGS := -lXext -lX11 -lm -lpthread

SRCDIR := ./srcs
SRCDIR_BONUS := ./srcs_bonus
OBJDIR := ./objs
OBJDIR_BONUS := ./objs_bonus

SRCS := draw.c hooks.c init.c main.c utils.c
SRCS_BONUS := draw_bonus.c draw_multithreads_bonus.c hooks_bonus.c init_bonus.c\
			main_bonus.c put_image_bonus.c utils_bonus.c
SRCS := $(addprefix $(SRCDIR)/, $(SRCS))
SRCS_BONUS := $(addprefix $(SRCDIR_BONUS)/, $(SRCS_BONUS))
OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
OBJS_BONUS := $(patsubst $(SRCDIR_BONUS)/%.c, $(OBJDIR_BONUS)/%.o, $(SRCS_BONUS))

INCLUDES := -I./includes

LIBFT := ./libft/libft.a
MLX := ./minilibx-linux/libmlx.a

NAME := fractol
NAME_BONUS := fractol_bonus
RM := rm -rf

all: $(NAME)

libft:
	@make -C libft;

mlx:
	@make -C minilibx-linux;

$(NAME): $(OBJS)
	@make -C libft;
	@make -C minilibx-linux;
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@if [ expr $(ls libft | wc -l) ]\
		|| [ expr $(ls minilibx-linux | wc -l) ]; then\
		git submodule init && git submodule update;\
	fi
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@make -C libft;
	@make -C minilibx-linux;
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_BONUS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME_BONUS)

$(OBJDIR_BONUS)/%.o: $(SRCDIR_BONUS)/%.c
	@if [ expr $(ls libft | wc -l) ]\
		|| [ expr $(ls minilibx-linux | wc -l) ]; then\
		git submodule init && git submodule update;\
	fi
	@mkdir -p $(OBJDIR_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C libft clean
	@make -C minilibx-linux clean
	$(RM) $(OBJDIR)
	$(RM) $(OBJDIR_BONUS)

fclean:
	@make -C libft fclean
	@make -C minilibx-linux clean
	$(RM) $(OBJDIR)
	$(RM) $(OBJDIR_BONUS)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all libft mlx clean fclean re bonus