/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_linep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:59:19 by avillar           #+#    #+#             */
/*   Updated: 2022/10/13 16:15:20 by avillar          ###   ########.fr       */
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

int	get_sr(int nb, int x, int i)
{
	if (nb > x)
		return (get_sr(nb / x, x, ++i));
	else
		return (++i);
}

char *convert(int nb)
{
	char *base;
	char *rt;
	int	x;

	x = (get_sr(nb , 16, 0));
	rt = malloc(sizeof(char) * (x + 1));
	if (!rt)
		exit(EXIT_FAILURE);
	base = "0123456789ABCDEF";
	rt[x] = '\0';
	x--;
	while (nb > 16 && x >= 0)
	{
		rt[x] = base[nb % 16];
		x--;
		nb = nb / 16;
	}
	rt[x] = base[nb];
	return (rt);
}

char	*convertcol(int nb, int nbx, int nbr)
{
	char *rtn;
	char *tmp;

	rtn = "0x";
	tmp = ft_strjoin(rtn, convert(nb));
	rtn = ft_strjoin(tmp, convert(nbx));
	free (tmp);
	tmp = ft_strjoin(rtn, convert(nbr));
	free (rtn);
	return (tmp);
}

void	draw_back(t_ddd **dd, t_cube *cube, int ceil, int floor)
{
	char	*pixel;
	int		i;
	int		x;

	i = -1;
	while (++i < (*dd)->winh / 2)
	{
		x = -1;
		while (++x < (*dd)->winw)
		{
			pixel = (*dd)->ml_img->addr + ((i * (*dd)->ml_img->line_len + x * ((*dd)->ml_img->bpp / 8)));
			*(int *)pixel = ceil;
		}
	}
	while (++i < (*dd)->winh)
	{
		x = -1;
		while (++x < (*dd)->winw)
		{
			pixel = (*dd)->ml_img->addr + ((i * (*dd)->ml_img->line_len + x * ((*dd)->ml_img->bpp / 8)));
			*(int *)pixel = floor;
		}
	}
}

void	draw_ddd(t_ddd *dd, t_cube *cube, t_ray *ray)
{
	float		h;
	int			y;
	int			i;

	y = ddwin_s / 2;
	i = -1;
	h = ddwin_s * Max_at / ray->eucli / 2;
	/*while (++i)
	{

	}*/
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
	draw_back(&dd, cube, 0xFF5641, 0x859574);
	mlx_put_image_to_window(cube->mlx->mlx_ptr, dd->win_ptr, dd->ml_img->mlx_img, 0, 0);
	/*while (pa < goal)
	{
		ray = ray_casting(cube, pa);

		if (ray->side == 0)
			ray->perpwdist = (ray->sidedist_x - ray->delta_x) ;*/
		/*pa += step;
		dd->index++;
		free (ray);
	}*/
}