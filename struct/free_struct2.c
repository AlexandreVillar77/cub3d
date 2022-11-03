/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:40:38 by avillar           #+#    #+#             */
/*   Updated: 2022/11/02 11:37:58 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	dest_mlx(t_cube *cube)
{
	if (!cube->mlx)
		return ;
	if (cube->mlx->mlx_ptr)
	{
		mlx_destroy_display(cube->mlx->mlx_ptr);
		free (cube->mlx->mlx_ptr);
	}
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
	if (cube->map->fcolor)
	{
		while (cube->map->fcolor[++i])
			free (cube->map->fcolor[i]);
		free (cube->map->fcolor);
	}
	i = -1;
	if (cube->map->cellcolor)
	{
		while (cube->map->cellcolor[++i])
			free (cube->map->cellcolor[i]);
		free (cube->map->cellcolor);
	}
}
