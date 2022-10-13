/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:24:23 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/13 16:13:16 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	handle_keypress(int keysym, t_cube *cube)
{
	if (keysym == ECHAP)
	{
		mlx_destroy_window(cube->mlx->mlx_ptr, cube->mlx->win_ptr);
		cube->mlx->win_ptr = NULL;
	}
	else
	{
		img_rotate_character(&cube->mlx->chara->char_img, cube, keysym);
	}
	/*printf("\nposx=%i   posy=%i\n", cube->mlx->chara->posx, cube->mlx->chara->posy);
	printf("angle:%f\n", cube->mlx->chara->pa);
	printf("axe x:%f    axe y:%f\n\n", cube->mlx->chara->pdx, cube->mlx->chara->pdy);*/
	return (0);
}

void	make_img(t_cube *cube)
{
	cube->mlx->img->mlx_img = mlx_new_image(cube->mlx->mlx_ptr
		, cube->mlx->win_sx, cube->mlx->win_sy);
	cube->mlx->img->addr = mlx_get_data_addr(cube->mlx->img->mlx_img
		, &cube->mlx->img->bpp, &cube->mlx->img->line_len, &cube->mlx->img->endian);
}

void	render_background(t_cube *cube, int color)
{
	int	i;
	int	j;
	int	a;
	int	c;

	i = 0;
	j = 0;
	while (j < cube->nline)
	{
		i = 0;
		while (cmap[j][i])
		{
			a = 0;
			c = 0;
			if (cmap[j][i] == '1')
				img_pix_put(&cube->mlx->img, i, j, 0xcd5c5c, cube);
			else if (cmap[j][i] != '1' && cmap[j][i] != ' ')
				img_pix_put(&cube->mlx->img, i, j, 0x5f9ea0, cube);
			i++;
		}
		j++;
	}
}

void	cube_put(t_img **img, int x, int y, int color, t_cube *cube)
{
	char	*pixel;
	int		py;
	int		px;

	py = -1;
	while (++py < (int)(squay / 15))
	{
		px = -1;
		while (++px < (int)(squax / 15))
		{
   			pixel = (*img)->addr + ((y * (*img)->line_len + x * ((*img)->bpp / 8)));
			*(int *)pixel = color;
			x++;
		}
		y++;
	}
}

void	put_cast_hit(t_cube *cube, int x, int y)
{
	int	i;
	int	d;
	t_img	*img;

	i = 0;
	d = 0;
	img = malloc(sizeof(t_img));
	if (!img)
		exit (EXIT_FAILURE);
	img->mlx_img = mlx_new_image(cube->mlx->mlx_ptr, (int)(squax / 15) , (int)(squay / 15));
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	cube_put(&img, 0, 0, 0x000000, cube);
	mlx_put_image_to_window(cube->mlx->mlx_ptr, cube->mlx->win_ptr, img->mlx_img, x, y);
	mlx_destroy_image(cube->mlx->mlx_ptr, img->mlx_img);
	free (img);
}

void	put_back_again2(t_cube *cube, t_img *img)
{
	int	x;
	int	y;
	int	sx;
	int	sy;

	sx = (int)(cube->mlx->chara->sx + cube->mlx->chara->sx * 1);
	sy = (int)(cube->mlx->chara->sy + cube->mlx->chara->sy * 1);
	x = cube->mlx->chara->posx;
	y = cube->mlx->chara->posy;
	if (cmap[y][x] != '1' && cmap[y][x] != ' ')
		mlx_put_image_to_window(cube->mlx->mlx_ptr, cube->mlx->win_ptr, img->mlx_img, x * squax, y * squay);
	if (cmap[y][x + 1] != '1')
		mlx_put_image_to_window(cube->mlx->mlx_ptr, cube->mlx->win_ptr, img->mlx_img, (x + 1) * squax, y * squay);
	if (cmap[y + 1][x + 1] != '1')
		mlx_put_image_to_window(cube->mlx->mlx_ptr, cube->mlx->win_ptr, img->mlx_img, (x + 1) * squax, (y + 1) * squay);
	if (cmap[y + 1][x] != '1')
		mlx_put_image_to_window(cube->mlx->mlx_ptr, cube->mlx->win_ptr, img->mlx_img, (x) * squax, (y + 1)* squay);
}

void	put_back_again(t_cube *cube)
{
	int	i;
	int	d;
	t_img	*img;

	i = 0;
	d = 0;
	img = malloc(sizeof(t_img));
	if (!img)
		exit (EXIT_FAILURE);
	img->mlx_img = mlx_new_image(cube->mlx->mlx_ptr, (int)squax , (int)squay);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	img_pix_put(&img, 0, 0, 0x5f9ea0, cube);
	put_back_again2(cube, img);
	mlx_destroy_image(cube->mlx->mlx_ptr, img->mlx_img);
	free (img);
}

int	render(t_cube *cube)
{
	if (cube->mlx->mapdone == 0)
	{
		cube->chara_move = 0;
		print_chara(cube);
		make_img(cube);
		render_background(cube, 0xf5f5f5);
		mlx_put_image_to_window(cube->mlx->mlx_ptr, cube->mlx->win_ptr, cube->mlx->img->mlx_img, 0, 0);
		cube->mlx->mapdone = 1;
		print_chara(cube);
		print_ver_line(cube);

	}
	if (cube->chara_move == 1)
	{
		cube->chara_move = 0;
		put_back_again(cube);
		print_chara(cube);
	}
	return (0);
}

//mlx_hook(cube->mlx->win_ptr, 17, 0, &handle_keypress, cube); pour fermer sur la croix rouge

void	ml_loop(t_cube *cube)
{
	//printf("test");
	mlx_loop_hook(cube->mlx->mlx_ptr, &render, cube);
	mlx_hook(cube->mlx->win_ptr, 02, 1L<<0, &handle_keypress, cube);
//mlx_hook(cube->mlx->win_ptr, 03, 0, &handle_stoppress, cube);
	//mlx_key_hook(cube->mlx->win_ptr, &handle_keypress, cube);
	if (cube->mlx->win_ptr && cube->mlx->mlx_ptr)
		mlx_loop(cube->mlx->mlx_ptr);
}
