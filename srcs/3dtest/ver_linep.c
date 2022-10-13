/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_linep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:59:19 by avillar           #+#    #+#             */
/*   Updated: 2022/10/13 15:25:05 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// fov = 60 degre
// taille fenetre 600 * 600
// donc incrementation de  l'angle = fov / taille fenetre

t_ddd	*init_ddd(t_cube *cube)
{
	t_ddd	*dd;

	dd = malloc(sizeof(t_ddd));
	dd->winw = ddwin_s;
	dd->winh = ddwin_s;
	dd->index = 0;
	dd->win_ptr = mlx_new_window(cube->mlx->mlx_ptr, dd->winw, dd->winh, "3d test");
	dd->ml_img = malloc(sizeof(t_img));
	dd->ml_img->mlx_img = mlx_new_image(cube->mlx->mlx_ptr, dd->winw, dd->winh);
	dd->ml_img->addr = mlx_get_data_addr(dd->ml_img->mlx_img, &dd->ml_img->bpp
		, &dd->ml_img->line_len, &dd->ml_img->endian);
	return (dd);
}

/*
pour taille mur texture produit en croix avec taille max mur soit taille de la fenetre donc
ddwin_s * distance a laquelle le mur fait sa taille max / la taille du rayon

donc faire attention a afficher les pixels que s'il feat dans la fenetre
*/

void	draw_ddd(t_ddd *dd, t_cube *cube, t_ray *ray)
{
	float		h;
	int			y;

	y = ddwin_s / 2;
	h = 
}

void	print_ver_line(t_cube *cube)
{
	t_ddd	*dd;
	int		x;
	t_ray	*ray;
	float	pa;
	float	goal;

	dd = init_ddd(cube);
	pa = cube->mlx->chara->pa - Pov_2;
	goal = cube->mlx->chara->pa + Pov_2;
	while (pa < goal)
	{
		ray = ray_casting(cube, pa);

		/*if (ray->side == 0)
			ray->perpwdist = (ray->sidedist_x - ray->delta_x) ;*/
		pa += step;
		dd->index++;
		free (ray);
	}
}