/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:04:56 by avillar           #+#    #+#             */
/*   Updated: 2022/11/02 11:10:29 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint8_t	*get_colors(char *s1, char *s2, char *s3)
{
	uint8_t	*col;

	col = malloc(sizeof(uint8_t) * 4);
	col[0] = ft_atoi(s1);
	col[1] = ft_atoi(s2);
	col[2] = ft_atoi(s3);
	col[3] = 0;
	return (col);
}

void	draw_north(t_ddd **dd, t_cube *cube, t_ray *ray)
{
	float		h;
	int			y;
	int			i;
	int			x;
	int			o;

	y = 4 * WINW * WINH / 2;
	o = y;
	i = 4 * DDWIN_S;
	x = 0;
	h = DDWIN_S * ((cube->mlx->squarex / 2) / tan(30 * (PI / 180)))
		/ ray->perpwdist / 2;
	cube->texture->no->index_b = ray->pos_rayy[0] % (int)cube->mlx->squarex;
	while (x < h / 2 && x < DDWIN_S / 2)
	{
		color_pixel((*dd)->backg->pimg + (y + (4 * (*dd)->index)),
			get_tex_color_bot(cube, cube->texture->no, h, x));
		color_pixel((*dd)->backg->pimg + (o - (i - (4 * (*dd)->index))),
			get_tex_color_top(cube, cube->texture->no, h, x));
		y += 4 * DDWIN_S;
		i += 4 * DDWIN_S;
		x++;
	}
}

void	draw_east(t_ddd **dd, t_cube *cube, t_ray *ray)
{
	float		h;
	int			y;
	int			i;
	int			x;
	int			o;

	y = 4 * WINW * WINH / 2;
	o = y;
	i = 4 * DDWIN_S;
	x = 0;
	h = DDWIN_S * ((cube->mlx->squarex / 2) / tan(30 * (PI / 180)))
		/ ray->perpwdist / 2;
	cube->texture->ea->index_b = ray->pos_rayx[1] % (int)cube->mlx->squarex;
	while (x < h / 2 && x < DDWIN_S / 2)
	{
		color_pixel((*dd)->backg->pimg + (y + (4 * (*dd)->index)),
			get_tex_color_bot(cube, cube->texture->ea, h, x));
		color_pixel((*dd)->backg->pimg + (o - (i - (4 * (*dd)->index))),
			get_tex_color_top(cube, cube->texture->ea, h, x));
		y += 4 * DDWIN_S;
		i += 4 * DDWIN_S;
		x++;
	}
}

void	draw_west(t_ddd **dd, t_cube *cube, t_ray *ray)
{
	float		h;
	int			y;
	int			i;
	int			x;
	int			o;

	y = 4 * WINW * WINH / 2;
	o = y;
	i = 4 * DDWIN_S;
	x = 0;
	h = DDWIN_S * ((cube->mlx->squarex / 2) / tan(30 * (PI / 180)))
		/ ray->perpwdist / 2;
	cube->texture->we->index_b = ray->pos_rayx[1] % (int)cube->mlx->squarex;
	while (x < h / 2 && x < DDWIN_S / 2)
	{
		color_pixel((*dd)->backg->pimg + (y + (4 * (*dd)->index)),
			get_tex_color_bot(cube, cube->texture->we, h, x));
		color_pixel((*dd)->backg->pimg + (o - (i - (4 * (*dd)->index))),
			get_tex_color_top(cube, cube->texture->we, h, x));
		y += 4 * DDWIN_S;
		i += 4 * DDWIN_S;
		x++;
	}
}

void	draw_south(t_ddd **dd, t_cube *cube, t_ray *ray)
{
	float		h;
	int			y;
	int			i;
	int			x;
	int			o;

	y = 4 * WINW * WINH / 2;
	o = y;
	i = 4 * DDWIN_S;
	x = 0;
	h = DDWIN_S * ((cube->mlx->squarex / 2) / tan(30 * (PI / 180)))
		/ ray->perpwdist / 2;
	cube->texture->so->index_b = ray->pos_rayy[0] % (int)cube->mlx->squarex;
	while (x < h / 2 && x < DDWIN_S / 2)
	{
		color_pixel((*dd)->backg->pimg + (y + (4 * (*dd)->index)),
			get_tex_color_bot(cube, cube->texture->so, h, x));
		color_pixel((*dd)->backg->pimg + (o - (i - (4 * (*dd)->index))),
			get_tex_color_top(cube, cube->texture->so, h, x));
		y += 4 * DDWIN_S;
		i += 4 * DDWIN_S;
		x++;
	}
}
