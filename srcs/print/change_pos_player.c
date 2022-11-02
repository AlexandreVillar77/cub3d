/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pos_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:56:43 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/02 10:49:54 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	img_rotate_character(t_cube *cube, int keysim)
{
	cube->chara_move = 1;
	if (keysim == DF)
		player_rotate_right(cube);
	else if (keysim == GF)
		player_rotate_left(cube);
	else if (keysim == S)
		player_down(cube);
	else if (keysim == W)
		player_up(cube);
	else if (keysim == A)
	{
		cube->mlx->chara->pixely += floor(cube->mlx->chara->pdx + 0.5);
		cube->mlx->chara->pixelx -= floor(cube->mlx->chara->pdy + 0.5);
	}
	else if (keysim == D)
	{
		cube->mlx->chara->pixely -= floor(cube->mlx->chara->pdx + 0.5);
		cube->mlx->chara->pixelx += floor(cube->mlx->chara->pdy + 0.5);
	}
	else
		cube->chara_move = 0;
}
