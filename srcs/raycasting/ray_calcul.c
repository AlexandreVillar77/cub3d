/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:17:09 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/03 14:19:10 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_ray	*ray_casting(t_cube *cube, float pa)
{
	t_ray	*ray;
	float	degree1;
	float	degree2;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	degree2 = pa * 180 / PI;
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
	degree1 = (float)((degree1 * (float)PI) / 180);
	ray->perpwdist = ray->eucli * sin(degree1);
	ray->perpwdist = (int)(floor(ray->perpwdist + 0.5));
	return (ray);
}

void	detect_wall(t_ray *ray, t_cube *cube)
{
	int	x;
	int	y;

	x = cube->mlx->chara->pixelx / (int)cube->mlx->squarex;
	y = cube->mlx->chara->pixely / (int)cube->mlx->squarey;
	if (y < 0 || x < 0)
		return ;
	if (y < cube->nline && x < cube->largestl)
		if (x < ft_strlen(cube->map->map[y]))
			if (cube->map->map[y][x] == '0' || cube->map->map[y][x] == 'N'
					|| cube->map->map[y][x] == 'W'
					|| cube->map->map[y][x] == 'S'
					|| cube->map->map[y][x] == 'E')
				check_ray(ray, cube);
	return ;
}

void	check_ray(t_ray *ray, t_cube *cube)
{
	setup_ray(cube, ray);
	while (1)
	{
		if ((ray->dist_y >= cube->mlx->squarey || ray->dist_y <= 0)
			&& (ray->dist_x >= cube->mlx->squarex || ray->dist_x <= 0))
			check_ray_middle(cube, ray);
		if (ray->dist_y >= cube->mlx->squarey || ray->dist_y <= 0)
		{
			check_wall_y(ray, cube, ray->x, ray->y);
			change_ray_y(cube, ray, &ray->dist_y);
		}
		else if (ray->dist_x >= cube->mlx->squarex || ray->dist_x <= 0)
		{
			check_wall_x(ray, cube, ray->x, ray->y);
			change_ray_x(cube, ray, &ray->dist_x);
		}
		if (ray->eucli != -1)
		{
			return_side(ray);
			break ;
		}
		modif_x_y(ray);
	}
}

void	check_wall_y(t_ray *ray, t_cube *cube, int x, int y)
{
	ray->pos_rayy[0] = x;
	ray->pos_rayy[1] = y;
	ray->nbr_delta[1]++;
	x = ray->pos_rayy[0] / cube->mlx->squarex;
	if (ray->pdy < 0)
		y = (ray->pos_rayy[1] - 1) / cube->mlx->squarey;
	else if (ray->pdy > 0)
		y = (ray->pos_rayy[1] + 1) / cube->mlx->squarey;
	if (cube->map->map[y][x] && cube->map->map[y][x] == '1')
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
	ray->nbr_delta[0]++;
	if (ray->pdx < 0)
		x = (ray->pos_rayx[0] - 1) / cube->mlx->squarex;
	else if (ray->pdx > 0)
		x = (ray->pos_rayx[0] + 1) / cube->mlx->squarex;
	y = ray->pos_rayx[1] / cube->mlx->squarey;
	if (cube->map->map[y][x] && cube->map->map[y][x] == '1')
	{
		ray->side = 0;
		calcul_eucli(ray, cube, 0);
	}
}
