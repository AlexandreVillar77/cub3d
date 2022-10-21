/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:51:41 by avillar           #+#    #+#             */
/*   Updated: 2022/10/21 11:21:58 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	dest_mlx(t_cube *cube)
{
	mlx_destroy_display(cube->mlx->mlx_ptr);
	free (cube->mlx->mlx_ptr);
	free (cube->mlx);
}

void	free_map_map(char **map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		free (map[x]);
		x++;
	}
	free (map);
}

void	free_splits(t_cube *cube)
{
	int	i;

	i = -1;
	if (cmfc)
	{
		while (cmfc[++i])
			free (cmfc[i]);
		free (cmfc);
	}
	i = -1;
	if (cmfc)
	{
		while (cmcc[++i])
			free (cmcc[i]);
		free (cmcc);
	}
}

void	free_map(t_cube *cube)
{
	if (cno)
		free (cno);
	free_splits(cube);
	if (cso)
		free (cso);
	if (cea)
		free (cea);
	if (cwe)
		free (cwe);
	if (cube->map->map)
		free_map_map(cube->map->map);
	if (cube->mapls)
		free (cube->mapls);
}

void	free_ddd(t_cube *cube)
{
	mlx_destroy_image(cube->mlx->mlx_ptr, cube->dd->backg->mlx_img);
	free (cube->dd->backg);
	free (cube->dd);
}

void	free_cube(t_cube *cube)
{
	free_map(cube);
	free (cube->mlx->chara);
	free_ddd(cube);
	dest_mlx(cube);
	free(cube->map);
	free(cube);
}
