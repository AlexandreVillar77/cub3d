/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:24:50 by avillar           #+#    #+#             */
/*   Updated: 2022/09/26 13:26:03 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_x(float px, float p, int max)
{
	if (px > 0 + max / p|| p < 0 - max / p)
	{
		if (px > 0)
			return (-1);
		else
			return (1);
	}
	return (0);
}

int	py_a(float py, float p, int max)
{
	if (p > 0)
	{
		if (py > 0)
			py -= p / max;
		return (py);
	}
	else
	{
		if (py < 0 )
			py += p / max;
		return (py);
	}
}

void	px_put_l(t_img **img, int x, int y, int color, t_cube *cube)
{
	int		i;
	char	*pixel;
	float	px;
	int		rx;
	int		ry;
	float	py;
	int		max;
	int		o;
	int		t;

	i = 0;
	max = cube->mlx->chara->sy;
	px = cos(cube->mlx->chara->pa) * max;
	py = sin(cube->mlx->chara->pa) * max;
	if (py < 0)
		py = py * -1;
	if (px < 0)
		px = px * -1;
	rx = (int)(max / px * 1);
	ry = (int)(max / py * 1);
	o = 0;
	t = 0;
	while (i < max && y > 0 && y < cube->mlx->chara->sy)
	{
		if (o == rx && rx != 0 && x > 0 && x < cube->mlx->chara->sx)
		{
			if (cpdx > 0)
				x--;
			else
				x++;
			o = 0;
		}
		if (t == ry && ry != 0 && y > 0 && y < cube->mlx->chara->sy  && x > 0 && x < cube->mlx->chara->sx)
		{
			if (cpdy > 0)
				y--;
			else
				y++;
			t = 0;
		}
		pixel = (*img)->addr + ((y * (*img)->line_len) + ((x) * ((*img)->bpp / 8)));
		*(int *)pixel = color;
		i++;
		o++;
		t++;
	}
}

void	print_o_line(t_cube *cube, t_img **line)
{
	int		x;
	int		y;
	int		i;

	y = (cube->mlx->chara->sy / 2);
	x = (cube->mlx->chara->sx / 2);
	px_put_l(line, x, y, 0xFF3333, cube);
}