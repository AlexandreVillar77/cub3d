/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:24:50 by avillar           #+#    #+#             */
/*   Updated: 2022/11/02 10:10:04 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_x(float px, float p, int max)
{
	if (px > 0 + max / p || p < 0 - max / p)
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
		if (py < 0)
			py += p / max;
		return (py);
	}
}
