/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:04:56 by avillar           #+#    #+#             */
/*   Updated: 2022/10/20 13:22:06 by thbierne         ###   ########.fr       */
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
	while (x < h / 2)
	{
		color_pixel((*dd)->backg->pimg + (y + (4 * (*dd)->index)), col);
		color_pixel((*dd)->backg->pimg + (o - (i - (4 * (*dd)->index))), col);
		y += 4 * ddwin_s;
		i += 4 * ddwin_s;
		//printf("i = %d\n", o - i);
		x++;
	}
	free (col);
}