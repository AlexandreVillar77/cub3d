/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:56:43 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/13 15:04:55 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		check_wall(t_cube *cube)
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
}

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

void	img_rotate_character(t_img **img, t_cube *cube, int keysim)
{
	t_ray *ray;
	//printf("\ntaillex:%f  tailley:%f\n", squax, squay);
	cube->chara_move = 1;
	if (keysim == D)
	{
		cube->mlx->chara->pa += 0.1;
		if (cube->mlx->chara->pa > 2 * pi)
			cube->mlx->chara->pa -= 2 * pi;
		cube->mlx->chara->pdx = cos(cube->mlx->chara->pa) * 10;
		cube->mlx->chara->pdy = sin(cube->mlx->chara->pa) * 10;
	}
	else if (keysim == A)
	{
		cube->mlx->chara->pa -= 0.1;
		if (cube->mlx->chara->pa < 0)
			cube->mlx->chara->pa += 2 * pi;
		cube->mlx->chara->pdx = cos(cube->mlx->chara->pa) * 10;
		cube->mlx->chara->pdy = sin(cube->mlx->chara->pa) * 10;
	}
	else if (keysim == S)
	{
		cpixelx += (int)(cube->mlx->chara->pdx * 1);
		cpixely += (int)(cube->mlx->chara->pdy * 1);
		/*if (check_wall(cube) == 1)
		{
			cpixelx -= (int)(cube->mlx->chara->pdx * 1);
			cpixely -= (int)(cube->mlx->chara->pdy * 1);
		}*/
	}
	else if (keysim == W)
	{
		cpixelx -= (int)(cube->mlx->chara->pdx * 1);
		cpixely -= (int)(cube->mlx->chara->pdy * 1);
		/*if (check_wall(cube) == 1)
		{
			cpixelx += (int)(cube->mlx->chara->pdx * 1);
			cpixely += (int)(cube->mlx->chara->pdy * 1);
		}*/
	}
	else
		cube->chara_move = 0;
	ray = ray_casting(cube, cube->mlx->chara->pa);
	/*printf("\nangle:%f\n", cube->mlx->chara->pa);
	printf("before : pixelx=%i   pixely=%i\n", cube->mlx->chara->pixelx, cube->mlx->chara->pixely);
	printf("axe x:%f    axe y:%f\n", cube->mlx->chara->pdx, cube->mlx->chara->pdy);
	printf("ray->x=%i    ray->y=%i\neucli=%f\n", ray->x, ray->y, ray->eucli);
	printf("ray->delta_x=%f  ray->sidedist_x=%f\n",ray->delta_x, ray->sidedist_x);
	printf("ray->delta_y=%f  ray->sidedist_y%f\n", ray->delta_y, ray->sidedist_y);
	printf("side=%i    nbr_delta=%i\n", ray->side, ray->nbr_delta);*/
	//put_cast_hit(cube, ray->x, ray->y);
}
