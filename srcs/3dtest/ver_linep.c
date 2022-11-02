/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_linep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:59:19 by avillar           #+#    #+#             */
/*   Updated: 2022/11/02 11:31:36 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_ddd(t_ddd *dd, t_cube *cube, t_ray *ray)
{
	if (ray->side == 1)
		(draw_south(&dd, cube, ray));
	else if (ray->side == 2)
		(draw_east(&dd, cube, ray));
	else if (ray->side == 3)
		draw_north(&dd, cube, ray);
	else if (ray->side == 4)
		(draw_west(&dd, cube, ray));
}

int	rcint(char **s, int i)
{
	int		rtn;

	rtn = ft_atoi(s[i - 1]);
	return (rtn);
}

t_img	*dra_b(t_cube *cube)
{
	uint8_t	*ceil;
	uint8_t	*floor;
	t_img	*backg;

	backg = NULL;
	ceil = malloc(sizeof(uint8_t) * 4);
	ceil[0] = rcint(cube->map->cellcolor, 3);
	ceil[1] = rcint(cube->map->cellcolor, 2);
	ceil[2] = rcint(cube->map->cellcolor, 1);
	ceil[3] = 0;
	floor = malloc(sizeof(uint8_t) * 4);
	floor[0] = rcint(cube->map->fcolor, 3);
	floor[1] = rcint(cube->map->fcolor, 2);
	floor[2] = rcint(cube->map->fcolor, 1);
	floor[3] = 0;
	backg = init_backg(cube);
	draw_back(&backg, ceil, floor);
	free (ceil);
	free (floor);
	return (backg);
}

// faire une nouvelle image rien que pour les mur comme ca 
// pas besoin de refaire le background a chaque fois
//jsute les put to window a la fin a la suite pour eviter les latence.

void	check_for_dd(t_cube *cube)
{
	t_ddd	*dd;

	dd = NULL;
	if (!cube->dd)
	{
		dd = init_ddd(cube);
		cube->dd = dd;
	}
	else if (cube->dd->backg)
	{
		mlx_destroy_image(cube->mlx->mlx_ptr, cube->dd->backg->mlx_img);
		free (cube->dd->backg);
	}
	cube->dd->backg = dra_b(cube);
	calcul_plan_chara(cube);
}

void	print_ver_line(t_cube *cube)
{
	t_ray	*ray;
	float	pa;
	float	goal;
	float	step;

	step = ((60 * (PI / 180)) / 1200);
	check_for_dd(cube);
	pa = cube->mlx->chara->pa - (step * (DDWIN_S / 2));
	goal = cube->mlx->chara->pa + (step * (DDWIN_S / 2));
	while (pa < goal - step)
	{
		ray = ray_casting(cube, pa);
		if (!ray)
			exit (EXIT_FAILURE);
		if (ray->eucli == -1)
		{
			free (ray);
			break ;
		}
		draw_ddd(cube->dd, cube, ray);
		pa += step;
		cube->dd->index++;
		free (ray);
	}
	cube->dd->index = 0;
}
