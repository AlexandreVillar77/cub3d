/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:18:48 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/06 11:40:13 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_t_ray(t_ray *x, t_ray *y, t_cube *cube)
{
	x->x = cpixelx;
	x->y = cpixely;
	x->eucli = -1;
	x->side = 0;
	x->delta_x = -1;
	x->delta_y = -1;
	x->sidedist_x = -1;
	x->sidedist_y = -1;
	x->nbr_delta = -1;
	y->x = cpixelx;
	y->y = cpixely;
	y->eucli = -1;
	y->side = 1;
	y->delta_x = -1;
	y->delta_y = -1;
	y->sidedist_x = -1;
	y->sidedist_y = -1;
	y->nbr_delta = -1;
}

void	calcul_sidedist_y(t_ray *y, t_cube *cube, int mode)
{
	int	diff_x;
	int	diff_y;

	if (mode == 0)
	{
		diff_x = y->x - cpixelx;
		diff_y = y->y - cpixely;
		if (diff_x < 0)
			diff_x *= -1;
		if (diff_y < 0)
			diff_y *= -1;
		y->sidedist_y = (diff_x * diff_x) + (diff_y * diff_y);
		y->sidedist_y = sqrtf(y->sidedist_y);
	}
	else
	{
		y->sidedist_y = cpixely - y->y;
	}
}

void	calcul_delta_y(t_ray *y, t_cube *cube)
{
	int	diff_x;
	int	diff_y;
	
	diff_x = y->x - cpixelx;
	diff_y = y->y - cpixely;
	if (diff_x < 0)
		diff_x *= -1;
	if (diff_y < 0)
		diff_y *= -1;
	y->delta_y = (diff_x * diff_x) + (diff_y * diff_y);
	y->delta_y = sqrtf(y->delta_y);
	y->delta_y -= y->sidedist_y;
}

void	calcul_sidedist_x(t_ray *x, t_cube *cube, int mode)
{
	int	diff_x;
	int	diff_y;

	if (mode == 0)
	{
		diff_y = x->y - cpixely;
		diff_x = x->x - cpixelx;
		if (diff_y < 0)
			diff_y *= -1;
		if (diff_x < 0)
			diff_x *= -1;
		x->sidedist_x = (diff_x * diff_x) + (diff_y * diff_y);
		x->sidedist_x = sqrtf(x->sidedist_x);
	}
	else
		x->sidedist_x = cpixelx - x->x;
}

void	calcul_delta_x(t_ray *x, t_cube *cube)
{
	int	diff_x;
	int	diff_y;
	
	diff_y = x->y - cpixely;
	diff_x = x->x - cpixelx;
	if (diff_x < 0)
		diff_x *= -1;
	if (diff_y < 0)
		diff_y *= -1;
	x->delta_x = (diff_x * diff_x) + (diff_y * diff_y);
	x->delta_x = sqrtf(x->delta_x);
	x->delta_x -= x->sidedist_x;
}

t_ray	*return_first_ray(t_ray *x, t_ray *y)
{
	if (x->eucli < y->eucli && x->eucli != -1 && x->y <= winH)
	{
		x->delta_y = y->delta_y;
		x->sidedist_y = y->sidedist_y;
		free(y);
		return (x);
	}
	else if (y->eucli != -1 && y->x <= winW)
	{
		y->delta_x = x->delta_x;
		y->sidedist_x = x->sidedist_x;
		free(x);
		return (y);
	}
	else if (y->eucli == -1)
	{
		x->delta_y = y->delta_y;
		x->sidedist_y = y->sidedist_y;
		free(y);
		return (x);
	}
	else if (x->eucli == -1)
	{
		y->delta_x = x->delta_x;
		y->sidedist_x = x->sidedist_x;
		free(x);
		return (y);
	}
	return (NULL);
}