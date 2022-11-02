/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:27:23 by avillar           #+#    #+#             */
/*   Updated: 2022/11/02 10:45:53 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	int		y;
	int		max;
	int		calc;

	max = 4 * data->size_x * data->size_y;
	y = max / 2;
	x_ratio = data->size_x * data->index_b / cube->mlx->squarex;
	y_ratio = data->size_y / h;
	calc = (int)((y + (4 * ((data->size_y
							* (int)(x * y_ratio))))) + (4 * (int)(x_ratio)));
	if (calc > max)
		data->index_b = -1;
	return (data->img->pimg + calc);
}

uint8_t	*get_tex_color_top(t_cube *cube, t_tdata *data, float h, int x)
{
	float	x_ratio;
	float	y_ratio;
	int		y;
	int		max;
	int		calc;

	max = 4 * data->size_x * data->size_y;
	y = max / 2;
	x_ratio = data->size_x * data->index_b / cube->mlx->squarex;
	y_ratio = data->size_y / h;
	calc = (int)((y - (4 * ((data->size_y
							* (int)(x * y_ratio))))) + (4 * (int)(x_ratio)));
	if (calc < 0)
		data->index_t = -1;
	return (data->img->pimg + calc);
}
