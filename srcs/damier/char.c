/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:11:34 by avillar           #+#    #+#             */
/*   Updated: 2022/10/20 15:27:03 by avillar          ###   ########.fr       */
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
	chara->char_img->pimg = NULL;
	chara->pdx = 0;
	chara->pdy = 0;
	chara->pa = 0;
	chara->p_per[0] = 0;
	chara->p_per[1] = 0;
	get_pos(chara, cube);
	return (chara);
}
