/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_ray_calcul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:14:38 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/03 10:14:40 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//	Digital Differential Analysis

float	ray_casting(t_cube *cube, float pa)
{
	int	x;
	int	y;
	int a;
	int b;
	float xy;
	float ab;

	x = -1;
	y = -1;
	a = -1;
	b = -1;
	xy = -1;
	while (check_ray_y(cube, pa, &x, &y, &xy) == 0)
		;
	if (x == -1)
		xy = check_y(cube, pa, &x, &y);
	//while (check_ray_x(cube, pa, &a, &b) == 0)
	//	;
	//ab = check_ray_x2(cube, pa, a, b);
	printf("xy:%f\n", xy);
	printf("valeur de x:%i   valeur de y:%i\n", x, y);
	//if (xy < ab)
	//	put_cast_hit(cube, x, y);
	//else
	//	put_cast_hit(cube, a, b);
	//y = y / squay;
	//x = x / squax;
	//b = b / squay;
	//a = a / squax;
	//if (xy <= ab)
	//	printf("x:%i y%i\n", x, y);
	//else
	//	printf("x:%i y%i\n", a, b);
}

int		check_ray_y(t_cube *cube, float pa, int *x, int *y, float *dist)
{
	float 	res_x;
	float	res_y;

	if (*x == -1 && *y == -1)
	{
		*x = cpixelx;
		*y = cpixely;
	}
	if (pa == (2 * pi) || pa == pi)
	{
		*y = -1;
		return (1);
	}
	else if (pa == (float)(pi / 2) || pa == (float)(pi + (pi / 2)))
	{
		*x = -1;
		return (1);
	}
	if (pa < pi)											//look up
	{
		res_y = *y % (int)squay;
		*y -= res_y;
		if (check_ray_y2(cube, pa, x, y) == 1)
		{
			res_x = cpixelx - *x;
			res_y = cpixely - *y;
			if (res_x < 0)
				res_x *= -1;
			if (res_y < 0)
				res_y *= -1;
			*dist = (res_x * res_x) + (res_y * res_y);
			*dist = sqrtf(*dist);
			return (1);
		}
	}
	else if	(cube->mlx->chara->pa > pi)						// look down
	{
		res_y = *y % (int)squay;
		res_y = squay - res_y;
		printf("res_y = %f\n", res_y);
		*y += res_y;
		if (check_ray_y2(cube, pa, x, y) == 1)
		{
			res_x = cpixelx - *x;
			res_y = cpixely - *y;
			if (res_x < 0)
				res_x *= -1;
			if (res_y < 0)
				res_y *= -1;
			*dist = (res_x * res_x) + (res_y * res_y);
			*dist = sqrtf(*dist);
			return (1);
		}
	}
	return (0);
}

int	check_ray_y2(t_cube *cube, float pa, int *x, int *y)
{
	int		diff_y;
	int		diff_x;
	float 	res_x;
	float	res_y;

	if (*x > winW || x < 0)
	{
		*x = winW + 1;
		return (1);
	}
	if (*y <= cpixely)
	{
		diff_y = cpixely - *y;
		res_y = diff_y / cube->mlx->chara->pdy;
		res_x = res_y * cube->mlx->chara->pdx;
		diff_x = *x + (int)(res_x * -1);
		*y = *y - 1;
	}
	else
	{
		diff_y = *y - cpixely;
		res_y = diff_y / cube->mlx->chara->pdy;
		res_x = res_y * cube->mlx->chara->pdx;
		diff_x = *x + (int)(res_x * -1);
		*y = *y + 1;
	}
	res_y = *y / squay;
	res_x = diff_x / squax;
	printf("valeur x:%f    valeur de y:%i\n", res_x, *y);
	if (cmap[(int)res_y][(int)res_x] && cmap[(int)res_y][(int)res_x] == '1')
	{
		if (*y <= cpixely)
			*y = *y + 1;
		else
			*y = *y - 1;
		*x = diff_x;
		return (1);
	}
	*x = diff_x;
	return (-1);
}

int	check_y(t_cube *cube, float pa, int *x, int *y)
{
	float 	res_x;
	float	res_y;

	*x = cpixelx;
	res_y = *y / squay;
	res_x = *x / squax;
	if (pa == (float)(pi / 2))
	{
		while (cmap[(int)res_y][(int)res_x] != '1')
		{
			res_y = *y % (int)squay;
			*y = *y - res_y;
			*y = *y - 1;
			res_y = *y / squay;
			res_x = *x / squax;
		}
		*y = *y + 1;
		return (cpixely - *y);
	}
	else if (pa == (float)(pi + (pi / 2)))
	{
		while (cmap[(int)res_y][(int)res_x] != '1')
		{
			res_y = *y % (int)squay;
			res_y = (int)squay - res_y;
			*y += res_y;
			*y = *y + 1;
			res_y = *y / squay;
			res_x = *x / squax;
		}
		*y = *y - 1;
		return (*y - cpixely);
	}
	return (0);
}

int		check_ray_x(t_cube *cube, float pa, int *x, int *y)
{
	float 	res_x;
	float	res_y;

	if (*x == -1 && *y == -1)
	{
		*x = cpixelx;
		*y = cpixely;
	}
	if (cube->mlx->chara->pa < (pi / 2) || cube->mlx->chara->pa > (pi + (pi / 2)))				//look left
	{
		res_x = *x % (int)squax;
		*x -= res_x;
		res_x = cpixelx - *x;
		*x = *x - 1;
		res_y = *y / squay;
		res_x = *x / squax;
		if (cmap[(int)res_y][(int)res_x] == '1')
			return (1);
	}
	else if	(cube->mlx->chara->pa > (pi / 2) && cube->mlx->chara->pa < (pi + (pi / 2)))			// look right
	{
		res_x = *x % (int)squax;
		res_x = (int)squax - res_x;
		*x += res_x;
		*x = *x + 1;
		res_y = *y / squay;
		res_x = *x / squax;
		if (cmap[(int)res_y][(int)res_x] == '1')
			return (1);
	}
	return (0);
}

float	check_ray_x2(t_cube *cube, float pa, int a, int b)
{
	int		diff_b;
	int		diff_a;
	float 	res_a;
	float	res_b;

	if (a <= cpixelx)
	{
		diff_a = cpixelx - a;
		res_a = diff_a / cube->mlx->chara->pdx;
		res_b = res_a * cube->mlx->chara->pdy;
		diff_b = b + (int)(res_b * -1);
	}
	else
	{
		diff_a = a - cpixelx;
		res_a = diff_a / cube->mlx->chara->pdx;
		res_b = res_a * cube->mlx->chara->pdy;
		diff_b = b + (int)(res_b * -1);
	}
	b = diff_b;
	pa = pa * (180 / pi);
	pa -= 90;
	if (pa < 0)
		pa *= -1;
	diff_b = cpixelx - b;
	if (diff_b < 0)
		diff_b = diff_b * -1;
	return (diff_b / (sin(pa) * -1));
}
