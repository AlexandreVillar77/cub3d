/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:49:47 by avillar           #+#    #+#             */
/*   Updated: 2022/09/21 09:09:22 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit(EXIT_FAILURE);
	map->Cellcolor = NULL;
	map->EA = NULL;
	map->Fcolor = NULL;
	map->map = NULL;
	map->NO = NULL;
	map->SO = NULL;
	map->WE = NULL;
	return (map);
}

t_mlx	*init_ml(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		exit (EXIT_FAILURE);
	mlx->img = malloc(sizeof(t_img));
	if (!mlx->img)
		exit (EXIT_FAILURE);
	mlx->mapdone = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, winW, winH, "test");
	mlx->win_sx = winW;
	mlx->win_sy = winH;
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
//	cube->mlx = init_ml();
	cube->largestl = 0;
	cube->nline = 0;
	cube->chara_move = 0;
	cube->mapls = NULL;
	return (cube);
}
