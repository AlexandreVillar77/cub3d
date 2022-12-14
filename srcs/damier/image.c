/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:24:23 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/03 14:20:05 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	update_posx_y(t_cube *cube)
{
	cube->mlx->chara->posx = cube->mlx->chara->pixelx / (int)cube->mlx->squarex;
	cube->mlx->chara->posy = cube->mlx->chara->pixely / (int)cube->mlx->squarey;
}

void	rotate(t_cube *cube)
{
	if (cube->key->np == 1)
		img_rotate_character(cube, W);
	if (cube->key->ep == 1)
		img_rotate_character(cube, D);
	if (cube->key->sp == 1)
		img_rotate_character(cube, S);
	if (cube->key->wp == 1)
		img_rotate_character(cube, A);
	if (cube->key->df == 1)
		img_rotate_character(cube, DF);
	if (cube->key->gf == 1)
		img_rotate_character(cube, GF);
}

int	render(t_cube *cube)
{
	int	posx;
	int	posy;

	posx = (int)((cube->mlx->chara->posx * cube->mlx->squarex)
			+ cube->mlx->squarex / 3);
	posy = (int)((cube->mlx->chara->posy * cube->mlx->squarey)
			+ cube->mlx->squarey / 3);
	if (cube->mlx->chara->pixelx == 0 && cube->mlx->chara->pixely == 0)
	{
		cube->mlx->chara->pixelx = posx;
		cube->mlx->chara->pixely = posy;
	}
	update_posx_y(cube);
	if (cube->chara_move == 1)
	{
		cube->chara_move = 0;
		print_ver_line(cube);
		mlx_put_image_to_window(cube->mlx->mlx_ptr, cube->dd->win_ptr,
			cube->dd->backg->mlx_img, 0, 0);
	}
	rotate(cube);
	return (0);
}

int	prog_leaver(t_cube *cube)
{
	mlx_destroy_window(cube->mlx->mlx_ptr, cube->dd->win_ptr);
	mlx_loop_end(cube->mlx->mlx_ptr);
	free_cube(cube);
	exit (0);
	return (0);
}

void	ml_loop(t_cube *cube)
{
	if (cube->dd->win_ptr && cube->mlx->mlx_ptr)
		mlx_loop_hook(cube->mlx->mlx_ptr, &render, cube);
	if (cube->dd->win_ptr && cube->mlx->mlx_ptr)
		mlx_hook(cube->dd->win_ptr, 17, 0, &prog_leaver, cube);
	if (cube->dd->win_ptr && cube->mlx->mlx_ptr)
		mlx_hook(cube->dd->win_ptr, 02, 1L << 0, &handle_keypress, cube);
	if (cube->dd->win_ptr && cube->mlx->mlx_ptr)
		mlx_hook(cube->dd->win_ptr, 03, 1L << 1, &handle_keyup, cube);
	if (cube->dd->win_ptr && cube->mlx->mlx_ptr)
		mlx_loop(cube->mlx->mlx_ptr);
}
