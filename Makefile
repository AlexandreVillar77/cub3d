# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 10:48:10 by thbierne          #+#    #+#              #
#    Updated: 2022/10/03 10:25:15 by thbierne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

SRCS =	srcs/cub3d.c								\
		srcs/print/get_size.c						\
		srcs/print/print_square.c					\
		srcs/arg_management/check_arg.c				\
		srcs/arg_management/handle_error.c			\
		srcs/arg_management/access_texture.c		\
		srcs/check_map/check_map.c					\
		srcs/check_map/print_error_player.c			\
		srcs/struct/init_struct.c					\
		srcs/struct/free_struct.c					\
		srcs/parsing/parse_cardi.c					\
		srcs/parsing/parse_color.c					\
		srcs/parsing/map_to_tab.c					\
		srcs/parsing/skip_error.c					\
		srcs/damier/image.c							\
		srcs/damier/dir.c							\
		srcs/damier/char.c							\
		srcs/raycasting/ray_calcul.c				\
		srcs/raycasting/ray_utils.c					\
		srcs/utils/utils1.c							\
		srcs/utils/utils2.c							\

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: libft/libft.a mlx_linux/libmlx.a $(NAME)

.c.o:
	$(CC) $(CFLAG) -Ilibft -Imlx_linux -c -I/include/cub3d.h $< -o $@

$(NAME): ${OBJS}
	$(CC) ${OBJS} -Llibft -lft $(LINUX) -lmlx -o $(NAME)

libft/libft.a:
	make -C libft

mlx_linux/libmlx.a:
	make -C mlx_linux

clean:
	rm -f ${OBJS}
	make -C libft clean
	make -C mlx_linux clean

fclean: clean
	rm -f ${NAME}
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re