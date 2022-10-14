/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:49:30 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/14 14:29:03 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;
	int		fd;
	void	*mlx_ptr;
	void	*win;

	if (check_arg(argc, argv) == 1)
		return (0);
	cube = init_cube();
	fd = open(argv[1], O_RDWR);
	read_keep(fd, NULL, 0, cube);
	tab_xy(cube);
	//print_map(cube);
	cube->mlx = init_ml();
	get_size_square(cube);
	ml_loop(cube);
	//printf("carre = %f\n", squax);
	free_cube(cube);
	close (fd);
	return (0);
}
