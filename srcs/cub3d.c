/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:49:30 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/03 11:22:11 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error(t_cube *cube)
{
	printf("Error\nerror in xpm file\n");
	free_cube (cube);
}

int	main(int argc, char **argv)
{
	t_cube	*cube;
	int		fd;

	if (check_arg(argc, argv) == 1)
		return (1);
	cube = init_cube();
	fd = open(argv[1], O_RDWR);
	read_keep(fd, cube);
	if (access_texture(cube->map) == 1 || check_map(cube->map) == 1)
	{
		free_cube(cube);
		return (1);
	}
	cube->mlx = init_ml();
	get_size_square(cube);
	cube->texture = init_texture(cube);
	if (!cube->texture)
	{
		error(cube);
		return (1);
	}
	cube->dd = init_ddd(cube);
	ml_loop(cube);
	free_cube(cube);
	return (0);
}
