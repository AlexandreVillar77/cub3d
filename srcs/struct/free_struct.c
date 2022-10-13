/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:51:41 by avillar           #+#    #+#             */
/*   Updated: 2022/09/16 11:19:10 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	dest_mlx(t_cube *cube)
{
	mlx_destroy_display(cube->mlx->mlx_ptr);
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

void	free_map(t_cube *cube)
{
	if (cno)
		free (cno);
	if (ccc)
		free (ccc);
	if (cso)
		free (cso);
	if (cea)
		free (cea);
	if (cwe)
		free (cwe);
	if (cfc)
		free (cfc);
	if (cube->map->map)
		free_map_map(cube->map->map);
}

void	free_cube(t_cube *cube)
{
	free_map(cube);
	//dest_mlx(cube);
	free(cube->map);
	free(cube);
}
