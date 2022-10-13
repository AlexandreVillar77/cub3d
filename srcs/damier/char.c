/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:11:34 by avillar           #+#    #+#             */
/*   Updated: 2022/09/26 15:58:30 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_pos(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (0);
	else
		return (1);
}

void	get_pos(t_chara *chara, t_cube *cube)
{
	int	stop;
	int	i;
	int	j;

	j = 0;
	stop = 0;
	while (cmap[j])
	{
		i = 0;
		while (cmap[j][i])
		{
			if (check_pos(cmap[j][i]) == 0)
				stop = -1;
			if (stop == -1)
				break ;
			i++;
		}
		if (stop == -1)
				break ;
		j++;
	}
	chara->posx = i;
	chara->posy = j;
	chara->dir = cmap[j][i];
}

t_chara	*init_char(t_cube *cube)
{
	t_chara	*chara;

	chara = malloc(sizeof(t_chara ));
	chara->char_img = malloc(sizeof(t_img ));
	if (!chara || !chara->char_img)
		exit (EXIT_FAILURE);
	chara->sx = cube->mlx->squarex / 4;
	chara->sy = cube->mlx->squarey / 4;
	chara->pixelx = 0;
	chara->pixely = 0;
	chara->char_img->mlx_img = mlx_new_image(cube->mlx->mlx_ptr, chara->sx, chara->sy);
	if (!chara->char_img->mlx_img)
		exit (EXIT_FAILURE);
	chara->char_img->addr = mlx_get_data_addr(chara->char_img->mlx_img, &chara->char_img->bpp
		, &chara->char_img->line_len, &chara->char_img->endian);
	get_pos(chara, cube);
	return (chara);
}

void	img_pix_put2(t_img **img, int x, int y, int color, t_cube *cube)
{
	char    *pixel;
	float		px;
	float		py;
	int		o;

	py = -1;
	o = x;
	/*while (++py < cube->mlx->chara->sy)
	{
		px = -1;
		x = o;
		while (++px < cube->mlx->chara->sx)
		{
   			pixel = (*img)->addr + ((y * (*img)->line_len + x * ((*img)->bpp / 8)));
			*(int *)pixel = color;
			x++;
		}
		y++;
	}*/
	//x = cube->mlx->chara->sx / 4;
	//y = cube->mlx->chara->sy / 4;
	py = - 1;
	o = x;
	while (++py < cube->mlx->chara->sy)
	{
		px =  - 1;
		x = o;
		while (++px < cube->mlx->chara->sx)
		{
   			pixel = (*img)->addr + ((y * (*img)->line_len + x * ((*img)->bpp / 8)));
			*(int *)pixel = 0xf7d51;
			x++;
		}
		y++;
	}
}

void	update_posx_y(t_cube *cube)
{
	cube->mlx->chara->posx = cube->mlx->chara->pixelx / (int)squax;
	cube->mlx->chara->posy = cube->mlx->chara->pixely / (int)squay;
}

void	print_chara(t_cube *cube)
{
	float	x;
	float	y;
	int	posy;
	int	posx;

	x = cube->mlx->chara->posx;
	y = cube->mlx->chara->posy;
	posx = (int)((x * squax) + squax / 3);
	posy = (int)((y * squay) + squay / 3);
	if (cpixelx == 0 && cpixely == 0)
	{
		cpixelx = posx;
		cpixely = posy;
	}
	img_pix_put2(&cube->mlx->chara->char_img, 0, 0, 0x5f9ea0, cube);
	print_o_line(cube, &cube->mlx->chara->char_img);
	mlx_put_image_to_window(cube->mlx->mlx_ptr, cube->mlx->win_ptr, cube->mlx->chara->char_img->mlx_img, cpixelx, cpixely);
	update_posx_y(cube);
}