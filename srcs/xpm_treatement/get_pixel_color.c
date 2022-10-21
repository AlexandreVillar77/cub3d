/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:27:23 by avillar           #+#    #+#             */
/*   Updated: 2022/10/21 16:10:09 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// h = hauteur du mur

uint8_t	get_tex_color(t_cube *cube, t_tdata *data, float h)
{
	int	i;
	int	j;
	float	x_ratio;
	float	y_ratio;
	
	x_ratio = data->size_x / h;
	y_ratio = data->size_y / h;
}