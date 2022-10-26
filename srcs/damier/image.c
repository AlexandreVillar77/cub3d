/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:24:23 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/26 11:15:22 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	handle_keypress(int keysym, t_cube *cube)
{
	if (keysym == ECHAP)
	{
		mlx_destroy_window(cube->mlx->mlx_ptr, cube->dd->win_ptr);
		cube->dd->win_ptr = NULL;
		mlx_loop_end(cube->mlx->mlx_ptr);
	}
	else
	{
		img_rotate_character(cube, keysym);
	}
	/*printf("\nposx=%i   posy=%i\n", cube->mlx->chara->posx, cube->mlx->chara->posy);
	printf("angle:%f\n", cube->mlx->chara->pa);
	printf("axe x:%f    axe y:%f\n\n", cube->mlx->chara->pdx, cube->mlx->chara->pdy);*/
	return (0);
}

void	update_posx_y(t_cube *cube)
{
	cube->mlx->chara->posx = cube->mlx->chara->pixelx / (int)squax;
	cube->mlx->chara->posy = cube->mlx->chara->pixely / (int)squay;
}

int	render(t_cube *cube)
{
	int posx;
	int posy;

	posx = (int)((cube->mlx->chara->posx * squax) + squax / 3);
	posy = (int)((cube->mlx->chara->posy * squay) + squay / 3);
	if (cpixelx == 0 && cpixely == 0)
	{
		cpixelx = posx;
		cpixely = posy;
	}
	update_posx_y(cube);
	if (cube->chara_move == 1)
	{
		cube->chara_move = 0;
		print_ver_line(cube);
	}
	return (0);
}

//mlx_hook(cube->mlx->win_ptr, 17, 0, &handle_keypress, cube); pour fermer sur la croix rouge

int	prog_leaver(t_cube *cube)
{
	/*if (cube->dd->win_ptr && cube->mlx->mlx_ptr)
	{
		mlx_destroy_display(cube->mlx->mlx_ptr);
		cube->dd->win_ptr = NULL;
	}*/
	mlx_destroy_window(cube->mlx->mlx_ptr, cube->dd->win_ptr);
	//mlx_destroy_display(cube->mlx->mlx_ptr);
//	cube->dd->win_ptr = NULL;
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
		mlx_hook(cube->dd->win_ptr, 02, 1L<<0, &handle_keypress, cube);
	if (cube->dd->win_ptr && cube->mlx->mlx_ptr)
		mlx_loop(cube->mlx->mlx_ptr);
}
