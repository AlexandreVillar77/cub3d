/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:56:43 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/20 16:57:14 by avillar          ###   ########.fr       */
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

void	img_pix_put(t_img **img, int x, int y, int color, t_cube *cube)
{
	char    *pixel;
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
	t_ray *ray;

	cube->chara_move = 1;
	if (keysim == DF)
	{
		cube->mlx->chara->pa += 0.1;
		if (cube->mlx->chara->pa > 2 * pi)
			cube->mlx->chara->pa -= 2 * pi;
		cube->mlx->chara->pdx = cos(cube->mlx->chara->pa) * 10;
		cube->mlx->chara->pdy = sin(cube->mlx->chara->pa) * 10;
	}
	else if (keysim == GF)
	{
		cube->mlx->chara->pa -= 0.1;
		if (cube->mlx->chara->pa < 0)
			cube->mlx->chara->pa += 2 * pi;
		cube->mlx->chara->pdx = cos(cube->mlx->chara->pa) * 10;
		cube->mlx->chara->pdy = sin(cube->mlx->chara->pa) * 10;
	}
	else if (keysim == S)
	{
		cpixelx += (int)(cube->mlx->chara->pdx * 3);
		cpixely += (int)(cube->mlx->chara->pdy * 3);
		/*if (check_wall(cube) == 1)
		{
			cpixelx -= (int)(cube->mlx->chara->pdx * 1);
			cpixely -= (int)(cube->mlx->chara->pdy * 1);
		}*/
	}
	else if (keysim == W)
	{
		cpixelx -= (int)(cube->mlx->chara->pdx * 3);
		cpixely -= (int)(cube->mlx->chara->pdy * 3);
		/*if (check_wall(cube) == 1)
		{
			cpixelx += (int)(cube->mlx->chara->pdx * 1);
			cpixely += (int)(cube->mlx->chara->pdy * 1);
		}*/
	}
	else if (keysim == D)
	{
		
	}
	else if (keysim == A)
	{
		
	}
	else
		cube->chara_move = 0;
	/*calcul_plan_chara(cube);
	ray = ray_casting(cube, cube->mlx->chara->pa);
	if (ray->side == 0)
		put_cast_hit(cube, ray->pos_rayx[0], ray->pos_rayx[1]);
	if (ray->side == 1)
		put_cast_hit(cube, ray->pos_rayy[0], ray->pos_rayy[1]);*/
}
