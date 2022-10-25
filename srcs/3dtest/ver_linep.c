/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_linep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:59:19 by avillar           #+#    #+#             */
/*   Updated: 2022/10/25 11:08:08 by avillar          ###   ########.fr       */
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
	dd->backg = NULL;
//	dd->ml_img = malloc(sizeof(t_img));
//	dd->ml_img->mlx_img = mlx_new_image(cube->mlx->mlx_ptr, dd->winw, dd->winh);
//	dd->ml_img->addr = mlx_get_data_addr(dd->ml_img->mlx_img, &dd->ml_img->bpp
//		, &dd->ml_img->line_len, &dd->ml_img->endian);
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

t_img	*init_backg(t_cube *cube)
{
	t_img *backg;

	backg = malloc(sizeof(t_img));
	if (!backg)
		exit (EXIT_FAILURE);
	backg->mlx_img = mlx_new_image(cube->mlx->mlx_ptr, ddwin_s, ddwin_s);
	backg->addr = mlx_get_data_addr(backg->mlx_img, &backg->bpp
		, &backg->line_len, &backg->endian);
	backg->pimg = (uint8_t *)backg->addr;
	return (backg);
}

void	color_pixel(uint8_t *pixel, uint8_t *color)
{
	pixel[0] = color[0];
	pixel[1] = color[1];
	pixel[2] = color[2];
	pixel[3] = color[3];
}

void	draw_back(t_img **backg, uint8_t *ceil, uint8_t *floor)
{
	int		i;
	int		a;

	i = 0;
	a = max_p;
	//printf("a = %d\n", a);
	while (i < a)
	{
		if (i < (a / 2))
			color_pixel((*backg)->pimg + i, ceil);
		if (i > (a / 2))
			color_pixel((*backg)->pimg + i, floor);
		i += 4;
	}
}

void	draw_ddd(t_ddd *dd, t_cube *cube, t_ray *ray)
{
	if (ray->side == 1)
		(draw_south(&dd, cube, ray, get_colors("0", "0", "0")));
	else if (ray->side == 2)
		(draw_east(&dd, cube, ray, get_colors("176", "0", "252")));
	else if (ray->side == 3)
		draw_north(&dd, cube, ray, get_colors("255", "255", "255"));	
	else if (ray->side == 4)
		(draw_west(&dd, cube, ray, get_colors("255", "87", "177")));
}

int		rcint(char **s, int i)
{
	int		rtn;

	rtn = ft_atoi(s[i - 1]);
	return (rtn);
}

t_img	*dra_b(t_cube *cube)
{
	uint8_t *ceil;
	uint8_t	*floor;
	t_img	*backg;

	backg = NULL;
	ceil = malloc(sizeof(uint8_t) * 4);
	ceil[0] = rcint(cmcc, 3);
	ceil[1] = rcint(cmcc, 2);
	ceil[2] = rcint(cmcc, 1);
	ceil[3] = 0;
	floor = malloc(sizeof(uint8_t) * 4);
	floor[0] = rcint(cmfc, 3);
	floor[1] = rcint(cmfc, 2);
	floor[2] = rcint(cmfc, 1);
	floor[3] = 0;
	//printf("%hhu , %hhu, %hhu, %hhu \n", floor[0], floor[1], floor[2], floor[3]);
	backg = init_backg(cube);
	draw_back(&backg, ceil, floor);
	free (ceil);
	free (floor);
	return (backg);
}

// faire une nouvelle image rien que pour les mur comme ca pas besoin de refaire le background a chaque fois
//jsute les put to window a la fin a la suite pour eviter les latence.

void	print_ver_line(t_cube *cube)
{
	t_ddd	*dd;
	t_ray	*ray;
	float	pa;
	float	goal;
	
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
	pa = cube->mlx->chara->pa - (step * (ddwin_s / 2));
	goal = cube->mlx->chara->pa + (step * (ddwin_s / 2));
	cube->dd->backg = dra_b(cube);
	calcul_plan_chara(cube);
	//reset_index(cube);
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
	mlx_put_image_to_window(cube->mlx->mlx_ptr, cube->dd->win_ptr, cube->dd->backg->mlx_img, 0, 0);
}