/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:51:41 by avillar           #+#    #+#             */
/*   Updated: 2022/11/02 11:37:41 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map(t_cube *cube)
{
	if (cube->map->no)
		free (cube->map->no);
	if (cube->map)
		free_splits(cube);
	if (cube->map->so)
		free (cube->map->so);
	if (cube->map->ea)
		free (cube->map->ea);
	if (cube->map->we)
		free (cube->map->we);
	if (cube->map)
		if (cube->map->map)
			free_map_map(cube->map->map);
	if (cube->mapls)
		free (cube->mapls);
}

void	free_ddd(t_cube *cube)
{
	if (!cube->dd)
		return ;
	if (cube->dd->backg)
		if (cube->dd->backg->mlx_img)
			mlx_destroy_image(cube->mlx->mlx_ptr, cube->dd->backg->mlx_img);
	if (cube->dd->backg)
		free (cube->dd->backg);
	if (cube->dd)
		free (cube->dd);
}

void	free_cube(t_cube *cube)
{
	if (!cube)
		return ;
	if (cube->texture)
		free_textures(cube, cube->texture);
	if (cube->map)
		free_map(cube);
	if (cube->mlx)
		if (cube->mlx->chara)
			free (cube->mlx->chara);
	free_ddd(cube);
	dest_mlx(cube);
	if (cube->map)
		free(cube->map);
	free(cube);
}
