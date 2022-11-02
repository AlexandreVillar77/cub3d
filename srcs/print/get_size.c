/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:07:21 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/02 10:51:20 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	alloc_pi(t_cube *cube)
{
	if (cube->mlx->chara->dir == 'N')
		return (PI / 2);
	else if (cube->mlx->chara->dir == 'E')
		return (PI);
	else if (cube->mlx->chara->dir == 'S')
		return (PI + (PI / 2));
	else if (cube->mlx->chara->dir == 'W')
		return (PI * 2);
	return (0);
}

void	get_size_square(t_cube *cube)
{
	cube->mlx->squaret = cube->largestl * cube->nline;
	cube->mlx->squarex = CSX;
	cube->mlx->squarey = CSX;
	cube->mlx->chara = init_char(cube);
	cube->mlx->chara->pa = alloc_pi(cube);
	cube->mlx->chara->pdx = cos(cube->mlx->chara->pa) * 30;
	cube->mlx->chara->pdy = sin(cube->mlx->chara->pa) * 30;
}
