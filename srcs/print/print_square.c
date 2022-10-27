/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:56:43 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/27 11:11:31 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	img_pix_put(t_img **img, int x, int y, int color, t_cube *cube)
{
	char	*pixel;
	int		px;
	int		py;
	int		o;

	py = -1;
	x *= squax;
	y *= squay;
	o = x;
	while (++py < squay - 1)
	{
		px = -1;
		x = o;
		while (++px < squax - 1)
		{
   			pixel = (*img)->addr + ((y * (*img)->line_len + x * ((*img)->bpp / 8)));
			*(int *)pixel = color;
			x++;
		}
		y++;
	}
}

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
		cpixely += floor(cube->mlx->chara->pdx + 0.5);
		cpixelx -= floor(cube->mlx->chara->pdy + 0.5);
	}
	else if (keysim == D)
	{

		cpixely -= floor(cube->mlx->chara->pdx + 0.5);
		cpixelx += floor(cube->mlx->chara->pdy + 0.5);
	}
	else
		cube->chara_move = 0;
	
}
