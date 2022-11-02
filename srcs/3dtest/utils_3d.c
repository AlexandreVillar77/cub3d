/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:27:47 by avillar           #+#    #+#             */
/*   Updated: 2022/11/02 11:03:43 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	a = 4 * WINW * WINH;
	while (i < a)
	{
		if (i < (a / 2))
			color_pixel((*backg)->pimg + i, ceil);
		if (i > (a / 2))
			color_pixel((*backg)->pimg + i, floor);
		i += 4;
	}
}
