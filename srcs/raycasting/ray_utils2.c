/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:13:49 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/03 10:44:10 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_ray_middle(t_cube *cube, t_ray *ray)
{
	ray->a = ray->y / cube->mlx->squarey;
	ray->b = (ray->x + (ray->pdx * 3)) / cube->mlx->squarex;
	ray->c = ray->y / cube->mlx->squarey;
	ray->d = (ray->x - (ray->pdx * 3)) / cube->mlx->squarex;
	if (cube->map->map[ray->a][ray->b] && cube->map->map[ray->a][ray->b] == '1'
		&& cube->map->map[ray->c][ray->d] == '1')
		change_ray_x(cube, ray, &ray->dist_x);
	else
		change_ray_y(cube, ray, &ray->dist_y);
}

void	alloc_delta(t_ray *ray, t_cube *cube, int i)
{
	float	x;
	float	y;

	if (i == 0)
	{
		x = cube->mlx->chara->pixelx - ray->pos_rayx[0];
		y = cube->mlx->chara->pixely - ray->pos_rayx[1];
	}
	else
	{
		x = cube->mlx->chara->pixelx - ray->pos_rayy[0];
		y = cube->mlx->chara->pixely - ray->pos_rayy[1];
	}
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	ray->delta[i] = (x * x) + (y * y);
	ray->delta[i] = sqrtf(ray->delta[i]) - ray->sidedist[i];
}

void	calcul_eucli(t_ray *ray, t_cube *cube, int i)
{
	long long int	x;
	long long int	y;

	if (i == 0)
	{
		x = (float)((float)cube->mlx->chara->pixelx - (float)ray->pos_rayx[0]);
		y = (float)((float)cube->mlx->chara->pixely - (float)ray->pos_rayx[1]);
	}
	else
	{
		x = (float)((float)cube->mlx->chara->pixelx - (float)ray->pos_rayy[0]);
		y = (float)((float)cube->mlx->chara->pixely - (float)ray->pos_rayy[1]);
	}
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	x = (x * x) + (y * y);
	ray->eucli = x;
	ray->eucli = sqrtf(ray->eucli);
}

void	alloc_sidedist(t_ray *ray, t_cube *cube, int i)
{
	float	x;
	float	y;

	if (i == 0)
	{
		x = (float)((float)cube->mlx->chara->pixelx - (float)ray->pos_rayx[0]);
		y = (float)((float)cube->mlx->chara->pixely - (float)ray->pos_rayx[1]);
	}
	else
	{
		x = (float)((float)cube->mlx->chara->pixelx - (float)ray->pos_rayy[0]);
		y = (float)((float)cube->mlx->chara->pixely - (float)ray->pos_rayy[1]);
	}
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	ray->sidedist[i] = (float)((float)(x * x) + (float)(y * y));
	ray->sidedist[i] = (float)(sqrtf(ray->sidedist[i]));
}

void	setup_ray(t_cube *cube, t_ray *ray)
{
	ray->x = cube->mlx->chara->pixelx;
	ray->y = cube->mlx->chara->pixely;
	ray->dist_x = fmod(cube->mlx->chara->pixelx, cube->mlx->squarex);
	ray->dist_y = fmod(cube->mlx->chara->pixely, cube->mlx->squarey);
}
