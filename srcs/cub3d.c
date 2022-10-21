/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:49:30 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/21 14:49:09 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;
	int		fd;

	if (check_arg(argc, argv) == 1)
		return (1);
	cube = init_cube();
	fd = open(argv[1], O_RDWR);
	read_keep(fd, cube);
	//cmap = put_space(cmap, get_largest_l(cmap), get_n_line(cmap));
	tab_xy(cube);
	//print_map(cube);
	if (access_texture(cube->map) == 1)
		return (1);
	if (check_map(cube->map) == 1)
		return (1);
	write(1, "f", 1);
	cube->mlx = init_ml();
	get_size_square(cube);
	cube->dd = init_ddd(cube);
	//cube->mlx->win_ptr = mlx_new_window(cube->mlx->mlx_ptr, winW, winH, "test");
	ml_loop(cube);
	//printf("carre = %f\n", squax);
	free_cube(cube);
	close (fd);
	return (0);
}
