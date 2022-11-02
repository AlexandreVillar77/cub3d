/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:57:08 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/02 10:52:45 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	player_up(t_cube *cube)
{
	cube->mlx->chara->pixelx -= floor(cube->mlx->chara->pdx + 0.5);
	cube->mlx->chara->pixely -= floor(cube->mlx->chara->pdy + 0.5);
}

void	player_down(t_cube *cube)
{
	cube->mlx->chara->pixelx += floor(cube->mlx->chara->pdx + 0.5);
	cube->mlx->chara->pixely += floor(cube->mlx->chara->pdy + 0.5);
}

void	player_rotate_left(t_cube *cube)
{
	cube->mlx->chara->pa -= 0.1;
	if (cube->mlx->chara->pa < 0)
		cube->mlx->chara->pa += 2 * PI;
	cube->mlx->chara->pdx = cos(cube->mlx->chara->pa) * 30;
	cube->mlx->chara->pdy = sin(cube->mlx->chara->pa) * 30;
}

void	player_rotate_right(t_cube *cube)
{
	cube->mlx->chara->pa += 0.1;
	if (cube->mlx->chara->pa > 2 * PI)
		cube->mlx->chara->pa -= 2 * PI;
	cube->mlx->chara->pdx = cos(cube->mlx->chara->pa) * 30;
	cube->mlx->chara->pdy = sin(cube->mlx->chara->pa) * 30;
}
