/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:27:23 by avillar           #+#    #+#             */
/*   Updated: 2022/10/25 10:11:36 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// h = hauteur du mur

void	reset_index(t_cube *cube)
{
	cube->texture->no->index_t = -1;
	cube->texture->so->index_t = -1;
	cube->texture->ea->index_t = -1;
	cube->texture->we->index_t = -1;
	cube->texture->no->index_b = -1;
	cube->texture->so->index_b = -1;
	cube->texture->ea->index_b = -1;
	cube->texture->we->index_b = -1;
}

uint8_t	*get_tex_color_bot(t_cube *cube, t_tdata *data, float h, int x)
{
	float	x_ratio;
	float	y_ratio;
	int	y;
	int		max;

	max = 4 * data->size_x * data->size_y;
	y = max / 2;
	x_ratio = data->size_x / h;
	y_ratio = data->size_y / h;
	(void)cube;
	if (g_colorb > max)
		data->index_b = -1;
	data->index_b++;
	return (data->img->pimg + g_colorb);
}

uint8_t	*get_tex_color_top(t_cube *cube, t_tdata *data, float h, int x)
{
	float	x_ratio;
	float	y_ratio;
	int		y;
	int		max;

	max = 4 * data->size_x * data->size_y;
	y = max / 2;
	x_ratio = data->size_x / h;
	y_ratio = data->size_y / h;
	(void)cube;
	if (g_colort < 0)
		data->index_t = -1;
	data->index_t++;
	return (data->img->pimg + g_colort);
}