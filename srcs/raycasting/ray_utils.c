/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:03:31 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/20 11:29:45 by avillar          ###   ########.fr       */
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

void	return_side(t_cube *cube, t_ray *ray)
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