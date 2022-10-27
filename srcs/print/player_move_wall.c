/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:01:25 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/24 10:08:27 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*int		check_wall(t_cube *cube)
{
	if (cmap[cube->mlx->chara->pixely / (int)squay][cube->mlx->chara->pixelx / (int)squax] == '1')
		return (1);
	else
		if (cmap[(cube->mlx->chara->pixely + (int)cube->mlx->chara->sy) / (int)squay][cube->mlx->chara->pixelx / (int)squax] == '1')
			return (1);
	else
		if (cmap[(cube->mlx->chara->pixely + (int)cube->mlx->chara->sy) / (int)squay][(cube->mlx->chara->pixelx + (int)cube->mlx->chara->sx) / (int)squax] == '1')
			return (1);
	else
		if (cmap[(cube->mlx->chara->pixely) / (int)squay][(cube->mlx->chara->pixelx + (int)cube->mlx->chara->sx) / (int)squax] == '1')
			return (1);
	else
		return (0);
}*/

void	player_up_wall(t_cube *cube)
{
	cpixelx -= (int)(cube->mlx->chara->pdx * 3);
	cpixely -= (int)(cube->mlx->chara->pdy * 3);
	if (check_wall(cube) == 1)
	{
		cpixelx += (int)(cube->mlx->chara->pdx * 1);
		cpixely += (int)(cube->mlx->chara->pdy * 1);
	}
}

void	player_down_wall(t_cube *cube)
{
	cpixelx += (int)(cube->mlx->chara->pdx * 3);
	cpixely += (int)(cube->mlx->chara->pdy * 3);
	if (check_wall(cube) == 1)
	{
		cpixelx -= (int)(cube->mlx->chara->pdx * 1);
		cpixely -= (int)(cube->mlx->chara->pdy * 1);
	}
}

void	player_rotate_left(t_cube *cube)
{
	cube->mlx->chara->pa -= 0.1;
	if (cube->mlx->chara->pa < 0)
		cube->mlx->chara->pa += 2 * pi;
	cube->mlx->chara->pdx = cos(cube->mlx->chara->pa) * 10;
	cube->mlx->chara->pdy = sin(cube->mlx->chara->pa) * 10;
}

void	player_rotate_right(t_cube *cube)
{
	cube->mlx->chara->pa += 0.1;
	if (cube->mlx->chara->pa > 2 * pi)
		cube->mlx->chara->pa -= 2 * pi;
	cube->mlx->chara->pdx = cos(cube->mlx->chara->pa) * 10;
	cube->mlx->chara->pdy = sin(cube->mlx->chara->pa) * 10;
}
