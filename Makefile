# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avillar <avillar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 10:48:10 by thbierne          #+#    #+#              #
#    Updated: 2022/11/02 10:28:34 by avillar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	srcs/cub3d.c								\
		srcs/print/get_size.c						\
		srcs/print/change_pos_player.c				\
		srcs/print/player_move.c					\
		srcs/arg_management/check_arg.c				\
		srcs/arg_management/handle_error.c			\
		srcs/arg_management/access_texture.c		\
		srcs/check_map/check_map.c					\
		srcs/check_map/print_error_player.c			\
		srcs/check_map/look_around.c				\
		srcs/struct/init_struct.c					\
		srcs/struct/free_struct.c					\
		srcs/struct/free_struct2.c					\
		srcs/parsing/parse_cardi.c					\
		srcs/parsing/parse_color.c					\
		srcs/parsing/map_to_tab.c					\
		srcs/parsing/skip_error.c					\
		srcs/parsing/size_texture.c					\
		srcs/damier/image.c							\
		srcs/damier/dir.c							\
		srcs/damier/char.c							\
		srcs/raycasting/ray_calcul.c				\
		srcs/raycasting/ray_utils.c					\
		srcs/raycasting/ray_utils2.c				\
		srcs/raycasting/ray_utils3.c				\
		srcs/utils/utils1.c							\
		srcs/utils/utils2.c							\
		srcs/3dtest/ver_linep.c						\
		srcs/3dtest/calcul_3d.c						\
		srcs/3dtest/utils_3d.c						\
		srcs/3dtest/draw_wall.c						\
		srcs/xpm_treatement/xpm_to_img.c			\
		srcs/xpm_treatement/get_pixel_color.c		\

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

FSAN = -g -fsanitize=address

FAST = -Ofast

LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: libft/libft.a mlx_linux/libmlx.a $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -Ilibft -Imlx_linux -c -I/include/cub3d.h $< -o $@

$(NAME): ${OBJS}
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $(SRCS)
	@$(CC) ${OBJS} -Llibft -lft $(LINUX) -lmlx -o $(NAME)
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Creating:\033[0m" $(NAME)

libft/libft.a:
	@make -C libft

mlx_linux/libmlx.a:
	@make -C mlx_linux

clean:
	@rm -f ${OBJS}
	@make -C libft clean
	@make -C mlx_linux clean

fclean: clean
	@rm -f ${NAME}
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re

.SILENT: $(OBJS)