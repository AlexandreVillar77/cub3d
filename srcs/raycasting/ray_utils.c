/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:03:31 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/24 11:07:22 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_t_ray(t_ray *ray, float pa, t_cube *cube)
{
	ray->pos_rayx[0] = cpixelx;
	ray->pos_rayx[1] = cpixely;
	ray->pos_rayy[0] = cpixelx;
	ray->pos_rayy[1] = cpixely;
	ray->pdx = cos(pa) * -1;
	ray->pdy = sin(pa) * -1;
	ray->nbr_delta[0] = -1;
	ray->nbr_delta[1] = -1;
	ray->delta[0] = -1;
	ray->delta[1] = -1;
	ray->sidedist[0] = -1;
	ray->sidedist[1] = -1;
	ray->eucli = -1;
	ray->side = 0;
	ray->perpwdist = 0;
}

void	return_side(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->pdx > 0)
			ray->side = 2;
		else
			ray->side = 4;
	}
	else if (ray->side == 1)
	{
		if (ray->pdy > 0)
			ray->side = 3;
		else
			ray->side = 1;
	}
}

void	calcul_plan_chara(t_cube *cube)
{
	cube->mlx->chara->p_per[0] = cube->mlx->chara->pa * 180 / pi;
	cube->mlx->chara->p_per[1] = cube->mlx->chara->p_per[0] + 90;
	cube->mlx->chara->p_per[0] -= 90;
}

void	change_ray_y(t_cube *cube, t_ray *ray, double *dist_y)
{
	if (*dist_y == 0)
		*dist_y = (double)squay;
	else if (*dist_y == squay)
		*dist_y = 0;
	else if (ray->pdy < 0)
	{
		*dist_y = (double)(*dist_y * -1);
		*dist_y = (double)(squay - *dist_y);
	}
	else
		*dist_y = (double)(*dist_y - squay);
}

void	change_ray_x(t_cube *cube, t_ray *ray, double *dist_x)
{
	if (*dist_x == 0)
		*dist_x = (double)squax;
	else if (*dist_x == squax)
		*dist_x = 0;
	else if (ray->pdx < 0)
	{
		*dist_x = (double)(*dist_x * -1);
		*dist_x = (double)(squax - *dist_x);
	}
	else
		*dist_x = (double)(*dist_x - squax);
}