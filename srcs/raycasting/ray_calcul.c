/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:17:09 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/24 13:15:05 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//	Digital Differential Analysis

t_ray	*ray_casting(t_cube *cube, float pa)
{
	t_ray	*ray;
	float	degree1;
	float	degree2;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	degree2 = pa * 180 / pi;
	init_t_ray(ray, pa, cube);
	detect_wall(ray, cube);
	degree1 = degree2 - cube->mlx->chara->p_per[0];
	degree2 = cube->mlx->chara->p_per[1] - degree2;
	if (degree2 < degree1)
		degree1 = degree2;
	if (degree1 == 90)
	{
		ray->perpwdist = ray->eucli;
		return (ray);
	}
	degree1 = (float)((degree1 * (float)pi) / 180);
	ray->perpwdist = ray->eucli * sin(degree1);
	ray->perpwdist = (int)(floor(ray->perpwdist + 0.5));
	return (ray);
}

void	detect_wall(t_ray *ray, t_cube *cube)
{
	int	x;
	int	y;

	x = cpixelx / (int)squax;
	y = cpixely / (int)squay;
	if (y < 0 || x < 0)
		return ;
	if (y < cube->nline && x < cube->largestl)
		if (x < ft_strlen(cmap[y]))
			if (cmap[y][x] == '0' || cmap[y][x] == 'N' || cmap[y][x] == 'W'
				|| cmap[y][x] == 'S' || cmap[y][x] == 'E')
				check_ray(ray, cube);
	return ;
}

void	check_ray(t_ray *ray, t_cube *cube)
{
	double 	dist_x;
	double 	dist_y;
	double	x;
	double 	y;
	int a;
	int b;
	int c;
	int d;

	x = cpixelx;
	y = cpixely;
	dist_x = fmod(cpixelx, squax);
	dist_y = fmod(cpixely, squay);
	while (1)
	{
		if ((dist_y >= squay || dist_y <= 0) && (dist_x >= squax || dist_x <= 0))
		{
			a = y / squay;
			b = (x + (ray->pdx * 3)) / squax;
			c = y / squay;
			d = (x - (ray->pdx * 3)) / squax;
			if (cmap[a][b] && cmap[a][b] == '1' && cmap[c][d] == '1')
				change_ray_x(cube, ray, &dist_x);
			else
				change_ray_y(cube, ray, &dist_y);
		}
		if (dist_y >= squay || dist_y <= 0)
		{
			check_wall_y(ray, cube, x, y);
			change_ray_y(cube, ray, &dist_y);
		}
		else if (dist_x >= squax || dist_x <= 0)
		{
			check_wall_x(ray, cube, x, y);
			change_ray_x(cube, ray, &dist_x);
		}
		if (ray->eucli != -1)
		{
			return_side(ray);
			break ;
		}
		dist_x += (double)ray->pdx;
		dist_y += (double)ray->pdy;
		x += (double)ray->pdx;
		y += (double)ray->pdy;
	}
}

void	check_wall_y(t_ray *ray, t_cube *cube, int x, int y)
{
	ray->pos_rayy[0] = x;
	ray->pos_rayy[1] = y;
	if (ray->sidedist[1] == -1)
		alloc_sidedist(ray, cube, 1);
	else if (ray->delta[1] == -1)
		alloc_delta(ray, cube, 1);
	ray->nbr_delta[1]++;
	x = ray->pos_rayy[0] / squax;
	if (ray->pdy < 0)
		y = (ray->pos_rayy[1] - 1) / squay;
	else if (ray->pdy > 0)
		y = (ray->pos_rayy[1] + 1) / squay;
	if (cmap[y][x] && cmap[y][x] == '1')
	{
		ray->side = 1;
		if (ray->pdy < 0)
			ray->pos_rayy[1] += 1;
		else
			ray->pos_rayy[1] -= 1;
		calcul_eucli(ray, cube, 1);
	}
}

void	check_wall_x(t_ray *ray, t_cube *cube, int x, int y)
{
	ray->pos_rayx[0] = x;
	ray->pos_rayx[1] = y;
	if (ray->sidedist[0] == -1)
		alloc_sidedist(ray, cube, 0);
	else if (ray->delta[0] == -1)
		alloc_delta(ray, cube, 0);
	ray->nbr_delta[0]++;
	if (ray->pdx < 0)
		x = (ray->pos_rayx[0] - 1) / squax;
	else if (ray->pdx > 0)
		x = (ray->pos_rayx[0] + 1) / squax;
	y = ray->pos_rayx[1] / squay;
	if (cmap[y][x] && cmap[y][x] == '1')
	{
		ray->side = 0;
		calcul_eucli(ray, cube, 0);
	}
}

void	calcul_eucli(t_ray *ray, t_cube *cube, int i)
{
	int		x;
	int		y;
	
	if (i == 0)
	{
		x = (float)((float)cpixelx - (float)ray->pos_rayx[0]);
		y = (float)((float)cpixely - (float)ray->pos_rayx[1]);
	}
	else
	{
		x = (float)((float)cpixelx - (float)ray->pos_rayy[0]);
		y = (float)((float)cpixely - (float)ray->pos_rayy[1]);
	}
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	ray->eucli = (float)((float)(x * x) + (float)(y * y));
	ray->eucli = (float)sqrtf(ray->eucli);
}

void	alloc_sidedist(t_ray *ray, t_cube *cube, int i)
{
	float	x;
	float	y;

	if (i == 0)
	{
		x = (float)((float)cpixelx - (float)ray->pos_rayx[0]);
		y = (float)((float)cpixely - (float)ray->pos_rayx[1]);
	}
	else
	{
		x = (float)((float)cpixelx - (float)ray->pos_rayy[0]);
		y = (float)((float)cpixely - (float)ray->pos_rayy[1]);
	}
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	ray->sidedist[i] = (float)((float)(x * x) + (float)(y * y));
	ray->sidedist[i] = (float)(sqrtf(ray->sidedist[i]));
}

void	alloc_delta(t_ray *ray, t_cube *cube, int i)
{
	float	x;
	float	y;

	if (i == 0)
	{
		x = cpixelx - ray->pos_rayx[0];
		y = cpixely - ray->pos_rayx[1];
	}
	else
	{
		x = cpixelx - ray->pos_rayy[0];
		y = cpixely - ray->pos_rayy[1];
	}
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	ray->delta[i] = (x * x) + (y * y);
	ray->delta[i] = sqrtf(ray->delta[i]) - ray->sidedist[i];
}