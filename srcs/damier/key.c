/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:19:38 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/03 14:23:47 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	handle_keys(int keysym, int n, t_cube *cube, int c)
{
	if (cube->key->move == c)
	{
		if (keysym == W)
			cube->key->np = n;
		else if (keysym == A)
			cube->key->wp = n;
		else if (keysym == D)
			cube->key->ep = n;
		else if (keysym == S)
			cube->key->sp = n;
		if (keysym == W || keysym == A || keysym == D || keysym == S)
			cube->key->move = n;
	}
	if (cube->key->turn == c)
	{
		if (keysym == GF)
			cube->key->gf = n;
		else if (keysym == DF)
			cube->key->df = n;
		if (keysym == GF || keysym == DF)
			cube->key->turn = n;
	}
}

int	handle_keyup(int keysym, t_cube *cube)
{
	if (keysym == W)
		cube->key->np = 0;
	else if (keysym == A)
		cube->key->wp = 0;
	else if (keysym == D)
		cube->key->ep = 0;
	else if (keysym == S)
		cube->key->sp = 0;
	if (keysym == W || keysym == A || keysym == D || keysym == S)
		cube->key->move = 0;
	if (keysym == GF)
	{
		cube->key->gf = 0;
		cube->key->turn = 0;
	}
	else if (keysym == DF)
	{
		cube->key->df = 0;
		cube->key->turn = 0;
	}
	return (0);
}

int	handle_keypress(int keysym, t_cube *cube)
{
	handle_keys(keysym, 1, cube, 0);
	if (keysym == ECHAP)
	{
		mlx_destroy_window(cube->mlx->mlx_ptr, cube->dd->win_ptr);
		cube->dd->win_ptr = NULL;
		mlx_loop_end(cube->mlx->mlx_ptr);
	}
	return (0);
}
