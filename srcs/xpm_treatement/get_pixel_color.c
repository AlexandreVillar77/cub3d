/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:27:23 by avillar           #+#    #+#             */
/*   Updated: 2022/10/24 11:13:20 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// h = hauteur du mur

uint8_t	*get_tex_color_bot(t_cube *cube, t_tdata *data, float h, int x)
{
	float	x_ratio;
	float	y_ratio;
	int	y;
	//uint8_t	*rtn;

	//rtn = malloc(sizeof(uint8_t) * 4);
	y = 4 * data->size_x * data->size_y / 2;
	x_ratio = data->size_x / h;
	y_ratio = data->size_y / h;
	//printf("test = %d\n", (int)(y + 4 * (data->size_y * (int)(x * y_ratio)) + (4 * (int)(cube->dd->index * x_ratio))));
	/*rtn[0] = data->img->pimg + (int)(y + 4 * (data->size_y * (int)(x * y_ratio)) + (4 * (int)(cube->dd->index * x_ratio)));
	rtn[1] = data->img->pimg + ((int)(y + 4 * (data->size_y * (int)(x * y_ratio)) + (4 * (int)(cube->dd->index * x_ratio))) + 1);
	rtn[2] = data->img->pimg + ((int)(y + 4 * (data->size_y * (int)(x * y_ratio)) + (4 * (int)(cube->dd->index * x_ratio))) + 2);
	rtn[3] = 0;
	*/return (data->img->pimg + g_color);
	//return (NULL);
}