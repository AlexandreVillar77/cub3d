/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:04:56 by avillar           #+#    #+#             */
/*   Updated: 2022/10/24 10:54:50 by avillar          ###   ########.fr       */
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

// y descend et x monte

void	draw_north(t_ddd **dd, t_cube *cube, t_ray *ray, uint8_t *col)
{
	float		h;
	int			y;
	int			i;
	int			x;
	int			o;

	y = max_p / 2;
	o = y;
	i = 4 * ddwin_s;
	x = 0;
	h = ddwin_s * Max_at / ray->perpwdist / 2;
	//printf("x = %f\n", (float)(cube->texture->no->size_x / cube->texture->no->size_y));
	//printf("test = %f, h = %f\n", (float)((cube->texture->no->size_x / cube->texture->no->size_y) * h), h);
	while (x < h / 2 && x < ddwin_s / 2)
	{
		color_pixel((*dd)->backg->pimg + (y + (4 * (*dd)->index)), get_tex_color_bot(cube, cube->texture->no, h, x ));
		color_pixel((*dd)->backg->pimg + (o - (i - (4 * (*dd)->index))), col);
		y += 4 * ddwin_s;
		i += 4 * ddwin_s;
		x++;
	}
	free (col);
}

void	draw_east(t_ddd **dd, t_cube *cube, t_ray *ray, uint8_t *col)
{
	float		h;
	int			y;
	int			i;
	int			x;
	int			o;

	y = max_p / 2;
	o = y;
	i = 4 * ddwin_s;
	x = 0;
	h = ddwin_s * Max_at / ray->perpwdist / 2;
	while (x < h / 2 && x < ddwin_s / 2)
	{
		color_pixel((*dd)->backg->pimg + (y + (4 * (*dd)->index)), get_tex_color_bot(cube, cube->texture->ea, h, x ));
		color_pixel((*dd)->backg->pimg + (o - (i - (4 * (*dd)->index))), col);
		y += 4 * ddwin_s;
		i += 4 * ddwin_s;
		x++;
	}
	free (col);
}

void	draw_west(t_ddd **dd, t_cube *cube, t_ray *ray, uint8_t *col)
{
	float		h;
	int			y;
	int			i;
	int			x;
	int			o;

	y = max_p / 2;
	o = y;
	i = 4 * ddwin_s;
	x = 0;
	h = ddwin_s * Max_at / ray->perpwdist / 2;
	while (x < h / 2 && x < ddwin_s / 2)
	{
		color_pixel((*dd)->backg->pimg + (y + (4 * (*dd)->index)), col);
		color_pixel((*dd)->backg->pimg + (o - (i - (4 * (*dd)->index))), col);
		y += 4 * ddwin_s;
		i += 4 * ddwin_s;
		x++;
	}
	free (col);
}

void	draw_south(t_ddd **dd, t_cube *cube, t_ray *ray, uint8_t *col)
{
	float		h;
	int			y;
	int			i;
	int			x;
	int			o;

	y = max_p / 2;
	o = y;
	i = 4 * ddwin_s;
	x = 0;
	h = ddwin_s * Max_at / ray->perpwdist / 2;
	while (x < h / 2 && x < ddwin_s / 2)
	{
		color_pixel((*dd)->backg->pimg + (y + (4 * (*dd)->index)), col);
		color_pixel((*dd)->backg->pimg + (o - (i - (4 * (*dd)->index))), col);
		y += 4 * ddwin_s;
		i += 4 * ddwin_s;
		x++;
	}
	free (col);
}