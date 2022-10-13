/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:17:09 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/06 15:10:16 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//	Digital Differential Analysis

t_ray	*ray_casting(t_cube *cube, float pa)
{
	t_ray *x;
	t_ray *y;

	x = malloc(sizeof(t_ray));
	y = malloc(sizeof(t_ray));
	if (!x || !y)
		exit(EXIT_FAILURE);
	init_t_ray(x, y, cube);
	while (check_ray_y(x, y, cube, pa) == 0)
		;
	if (y->x == -1)
		y->eucli = check_y(x, y, cube, pa);
	while (check_ray_x(x, y, cube, pa) == 0)
		;
	if (x->y == -1)
		x->eucli = check_x_ray(x, y, cube, pa);
	return (return_first_ray(x, y));
}

int		check_ray_y(t_ray *x, t_ray *y, t_cube *cube, float pa)
{
	float 	res_x;
	float	res_y;

	if (pa == (float)(2 * pi) || pa == (float)pi)
	{
		y->y = -1;
		return (1);
	}
	else if (pa == (float)(pi / 2) || pa == (float)(pi + (pi / 2)))
	{
		y->x = -1;
		return (1);
	}
	if (pa < pi)											//look up
	{
		res_y = y->y % (int)squay;
		y->y -= res_y;
		if (check_ray_y2(x, y, cube, pa) == 1)
		{
			res_x = cpixelx - y->x;
			res_y = cpixely - y->y;
			if (res_x < 0)
				res_x *= -1;
			if (res_y < 0)
				res_y *= -1;
			y->eucli = (res_x * res_x) + (res_y * res_y);
			y->eucli = sqrtf(y->eucli);
			return (1);
		}
	}
	else if	(cube->mlx->chara->pa > pi)						// look down
	{
		res_y = y->y % (int)squay;
		res_y = squay - res_y;
		y->y += res_y;
		if (check_ray_y2(x, y, cube, pa) == 1)
		{
			res_x = cpixelx - y->x;
			res_y = cpixely - y->y;
			if (res_x < 0)
				res_x *= -1;
			if (res_y < 0)
				res_y *= -1;
			y->eucli = (res_x * res_x) + (res_y * res_y);
			y->eucli = sqrtf(y->eucli);
			return (1);
		}
	}
	return (0);
}

int	check_ray_y2(t_ray *x, t_ray *y, t_cube *cube, float pa)
{
	float		diff_y;
	float		diff_x;
	float 		res_x;
	float		res_y;

	y->nbr_delta++;
	if (y->y <= cpixely)
	{
		diff_y = cpixely - y->y;
		res_y = diff_y / cube->mlx->chara->pdy;
		res_x = res_y * cube->mlx->chara->pdx;
		diff_x = y->x + (res_x * -1);
		y->y = y->y - 1;
	}
	else
	{
		diff_y = y->y - cpixely;
		res_y = diff_y / cube->mlx->chara->pdy;
		res_x = res_y * cube->mlx->chara->pdx;
		diff_x = y->x - (res_x * -1);
		y->y = y->y + 1;
	}
	y->x = diff_x;
	if (y->x > winW || y->x < 0)
	{
		y->x = winW + 1;
		if (y->y <= cpixely)
			y->y = y->y + 1;
		else
			y->y = y->y - 1;
		return (1);
	}
	if (y->sidedist_y < 0)
		calcul_sidedist_y(y, cube, 0);
	else if (y->delta_y < 0)
		calcul_delta_y(y, cube);
	res_y = y->y / squay;
	res_x = diff_x / squax;
	if (cmap[(int)res_y][(int)res_x] && cmap[(int)res_y][(int)res_x] == '1')
	{
		if (y->y <= cpixely)
			y->y = y->y + 1;
		else
			y->y = y->y - 1;
		return (1);
	}
	return (-1);
}

int	check_y(t_ray *x, t_ray *y, t_cube *cube, float pa)
{
	float 	res_x;
	float	res_y;

	y->x = cpixelx;
	res_y = y->y / squay;
	res_x = y->x / squax;
	if (pa == (float)(pi / 2))
	{
		while (cmap[(int)res_y][(int)res_x] != '1')
		{
			y->nbr_delta++;
			res_y = y->y % (int)squay;
			y->y = y->y - res_y;
			if (y->sidedist_y < 0)
				calcul_sidedist_y(y, cube, 1);
			else if (y->delta_y < 0)
				y->delta_y = squay;
			y->y = y->y - 1;
			res_y = y->y / squay;
			res_x = y->x / squax;
		}
		y->y = y->y + 1;
		return (cpixely - y->y);
	}
	else if (pa == (float)(pi + (pi / 2)))
	{
		while (cmap[(int)res_y][(int)res_x] != '1')
		{
			y->nbr_delta++;
			res_y = y->y % (int)squay;
			res_y = (int)squay - res_y;
			if (y->sidedist_y < 0)
				calcul_sidedist_y(y, cube, 1);
			else if (y->delta_y < 0)
				y->delta_y = squay;
			y->y += res_y;
			y->y = y->y + 1;
			res_y = y->y / squay;
			res_x = y->x / squax;
		}
		y->y = y->y - 1;
		return (y->y - cpixely);
	}
	return (0);
}

int		check_ray_x(t_ray *x, t_ray *y, t_cube *cube, float pa)
{
	float 	res_x;
	float	res_y;

	if (pa == (2 * pi) || pa == pi)
	{
		x->y = -1;
		return (1);
	}
	else if (pa == (float)(pi / 2) || pa == (float)(pi + (pi / 2)))
	{
		x->x = -1;
		return (1);
	}
	if (pa > (float)(pi / 2) && pa < (float)(pi + (pi / 2)))	// look right
	{
		res_x = x->x % (int)squax;
		res_x = squax - res_x;
		x->x += res_x;
		if (check_ray_x2(x, y, cube, pa) == 1)
		{
			res_y = cpixely - x->y;
			res_x = cpixelx - x->x;
			if (res_x < 0)
				res_x *= -1;
			if (res_y < 0)
				res_y *= -1;
			x->eucli = (res_x * res_x) + (res_y * res_y);
			x->eucli = sqrtf(x->eucli);
			return (1);
		}
	}
	else														//look left
	{
		res_x = x->x % (int)squax;
		x->x -= res_x;
		if (check_ray_x2(x, y, cube, pa) == 1)
		{
			res_y = cpixely - x->y;
			res_x = cpixelx - x->x;
			if (res_y < 0)
				res_y *= -1;
			if (res_x < 0)
				res_x *= -1;
			x->eucli = (res_x * res_x) + (res_y * res_y);
			x->eucli = sqrtf(x->eucli);
			return (1);
		}
	}
	return (0);
}

int	check_ray_x2(t_ray *x, t_ray *y, t_cube *cube, float pa)
{
	float		diff_y;
	float		diff_x;
	float 		res_x;
	float		res_y;

	x->nbr_delta++;
	if (x->x <= cpixelx)
	{
		diff_x = cpixelx - x->x;
		res_x = diff_x / cube->mlx->chara->pdx;
		res_y = res_x * cube->mlx->chara->pdy;
		diff_y = x->y + (res_y * -1);
		x->x = x->x - 1;
	}
	else
	{
		diff_x = x->x - cpixelx;
		res_x = diff_x / cube->mlx->chara->pdx;
		res_y = res_x * cube->mlx->chara->pdy;
		diff_y = x->y - (res_y * -1);
		x->x = x->x + 1;
	}
	x->y = diff_y;
	if (x->y > winH || x->y < 0)
	{
		x->y = winH + 1;
		if (x->x <= cpixelx)
			x->x = x->x + 1;
		else
			x->x = x->x - 1;
		return (1);
	}
	if (x->sidedist_x < 0)
		calcul_sidedist_x(x, cube, 0);
	else if (x->delta_x < 0)
		calcul_delta_x(x, cube);
	res_x = x->x / squax;
	res_y = diff_y / squay;
	if (cmap[(int)res_y][(int)res_x] && cmap[(int)res_y][(int)res_x] == '1')
	{
		if (x->x <= cpixelx)
			x->x = x->x + 1;
		else
			x->x = x->x - 1;
		return (1);
	}
	return (-1);
}

int	check_x_ray(t_ray *x, t_ray *y, t_cube *cube, float pa)
{
	float 	res_x;
	float	res_y;

	x->y = cpixely;
	res_x = x->x / squax;
	res_y = x->y / squay;
	if (pa == (2 * pi) || pa == 0)
	{
		while (cmap[(int)res_y][(int)res_x] != '1')
		{
			x->nbr_delta++;
			res_x = x->x % (int)squax;
			x->x = x->x - res_x;
			if (x->sidedist_x < 0)
				calcul_sidedist_x(x, cube, 1);
			else if (x->delta_x < 0)
				x->delta_x = squax;
			x->x = x->x - 1;
			res_y = y->y / squay;
			res_x = y->x / squax;
		}
		x->x = x->x + 1;
		return (cpixelx - x->x);
	}
	else if (pa == pi)
	{
		while (cmap[(int)res_y][(int)res_x] != '1')
		{
			x->nbr_delta++;
			res_x = x->x % (int)squax;
			res_x = (int)squax - res_x;
			if (x->sidedist_x < 0)
				calcul_sidedist_x(x, cube, 1);
			else if (x->delta_x < 0)
				x->delta_x = squax;
			x->x += res_x;
			x->x = x->x + 1;
			res_y = y->y / squay;
			res_x = y->x / squax;
		}
		x->x = x->x - 1;
		return (x->x - cpixelx);
	}
	return (0);
}
