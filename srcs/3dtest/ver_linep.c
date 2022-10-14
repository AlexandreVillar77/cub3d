/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_linep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:59:19 by avillar           #+#    #+#             */
/*   Updated: 2022/10/14 15:25:06 by avillar          ###   ########.fr       */
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
	dd->backg = malloc(sizeof(t_img));
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

	rt = malloc(sizeof(char) * (3));
	if (!rt)
		exit(EXIT_FAILURE);
	rt[0] = '0';
	rt[1] = '0';
	base = "0123456789ABCDEF";
	x = 1;
	while (nb > 16 && x >= 0)
	{
		rt[x] = base[nb % 16];
		x--;
		nb = nb / 16;
	}
	rt[x] = base[nb];
	rt[2] = '\0';
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

void	init_backg(t_ddd **dd, t_cube *cube)
{
	(*dd)->backg->mlx_img = mlx_new_image(cube->mlx->mlx_ptr, (*dd)->winw, (*dd)->winh);
	(*dd)->backg->addr = mlx_get_data_addr((*dd)->backg->mlx_img, &(*dd)->backg->bpp
		, &(*dd)->backg->line_len, &(*dd)->backg->endian);
	(*dd)->backg->pimg = (uint8_t *)(*dd)->backg->addr;
}

void	color_pixel(uint8_t *pixel, uint8_t *color)
{
	pixel[0] = color[0];
	pixel[1] = color[1];
	pixel[2] = color[2];
	pixel[3] = color[3];
}

void	draw_back(t_ddd **dd, t_cube *cube, uint8_t *ceil, int floor)
{
	int		i;
	int		x;
	int		a;

	i = 0;
	a = 4 * (*dd)->winh * (*dd)->winh;
	while (i < a)
	{
		if (i < (a / 2))
			color_pixel((*dd)->backg->pimg + i, ceil);
		i += 4;
	}
	/*while (++i < (*dd)->winh)
	{
		x = -1;
		while (++x < (*dd)->winw)
		{
			pixel = (*dd)->backg->addr + ((i * (*dd)->backg->line_len + x * ((*dd)->backg->bpp / 8)));
			*(int *)pixel = floor;
		}
	}*/
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

int		rcint(char **s, int i)
{
	int		rtn;

	rtn = ft_atoi(s[i - 1]);
	return (rtn);
}

void	dra_b(t_ddd *dd, t_cube *cube)
{
	char *ceilc;
	char *floorc;
	uint8_t *test;

	test = malloc(sizeof(uint8_t) * 4);
	test[0] = rcint(cmcc, 1);
	test[1] = rcint(cmcc, 2);
	test[2] = rcint(cmcc, 3);
	test[3] = 0;
	printf("color = %d\n", test[0]);
	printf("color = %d\n", test[1]);
	printf("color = %d\n", test[2]);
//	printf("test = %d\n", test[0]);
	ceilc = convertcol(rcint(cmcc, 1), rcint(cmcc, 2), rcint(cmcc, 3));
	floorc = convertcol(rcint(cmfc, 1), rcint(cmfc, 2), rcint(cmfc, 3));
	printf("colors = %s\n colors = %s\n", ceilc, floorc);
	init_backg(&dd, cube);
	draw_back(&dd, cube, test, floorc);
}

void	print_ver_line(t_cube *cube)
{
	t_ddd	*dd;
	int		x;
	t_ray	*ray;
	float	pa;
	float	goal;

int	i;

i = 0;
while (i < 3)
{
	printf("cmfc[%d] = %s\n", i, cmfc[i]);
	i++;
}
	dd = init_ddd(cube);
	pa = cube->mlx->chara->pa - Pov_2;
	goal = cube->mlx->chara->pa + Pov_2;
	if (!dd->backg->addr)
	{
		dra_b(dd, cube);
	}
/*	while (pa < goal)
	{
		ray = ray_casting(cube, pa);

		if (ray->side == 0)
			ray->perpwdist = (ray->sidedist_x - ray->delta_x) ;*/
		/*pa += step;
		dd->index++;
		free (ray);
	}*/
	mlx_put_image_to_window(cube->mlx->mlx_ptr, dd->win_ptr, dd->backg->mlx_img, 0, 0);
}