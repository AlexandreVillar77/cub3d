/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:49:47 by avillar           #+#    #+#             */
/*   Updated: 2022/11/02 14:16:14 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit(EXIT_FAILURE);
	map->error = 0;
	map->cellcolor = NULL;
	map->fcolor = NULL;
	map->map = NULL;
	map->no = NULL;
	map->ea = NULL;
	map->so = NULL;
	map->we = NULL;
	return (map);
}

t_mlx	*init_ml(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		exit (EXIT_FAILURE);
	mlx->img = NULL;
	mlx->mapdone = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = NULL;
	mlx->win_sx = WINW;
	mlx->win_sy = WINH;
	mlx->x = 0;
	mlx->y = 0;
	mlx->squarex = 0;
	mlx->squarey = 0;
	mlx->squaret = 0;
	return (mlx);
}

t_cube	*init_cube(void)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	if (!cube)
		exit (EXIT_FAILURE);
	cube->map = init_map();
	cube->mlx = NULL;
	cube->largestl = 0;
	cube->nline = 0;
	cube->chara_move = 1;
	cube->mapls = NULL;
	cube->dd = NULL;
	cube->texture = NULL;
	cube->keyp = 0;
	cube->keysym = 0;
	return (cube);
}
