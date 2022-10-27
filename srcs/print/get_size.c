/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:07:21 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/27 10:58:49 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	alloc_pi(t_cube *cube)
{
	if (cube->mlx->chara->dir == 'N')
		return (pi / 2);
	else if (cube->mlx->chara->dir == 'E')
		return (pi);
	else if (cube->mlx->chara->dir == 'S')
		return (pi + (pi / 2));
	else if (cube->mlx->chara->dir == 'W')
		return (pi * 2);
	return (0);
}

void	get_size_square(t_cube *cube)
{
	cube->mlx->squaret = cube->largestl * cube->nline;
	squax = Csx;
	squay = Csx;
	cube->mlx->chara = init_char(cube);
	cube->mlx->chara->pa = alloc_pi(cube);
	cube->mlx->chara->pdx = cos(cube->mlx->chara->pa) * 30;
	cube->mlx->chara->pdy = sin(cube->mlx->chara->pa) * 30;
}
