/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:43:38 by avillar           #+#    #+#             */
/*   Updated: 2022/10/21 15:25:18 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_tdata	*init_tdata(t_cube *cube, char *filename)
{
	t_tdata	*data;

	data = malloc(sizeof(t_tdata));
	if (!data)
		exit (EXIT_FAILURE);
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		exit (EXIT_FAILURE);
	data->img->mlx_img = mlx_xpm_file_to_image(cube->mlx->mlx_ptr, filename,
			&data->size_x, &data->size_y);
	if (!data->img->mlx_img)
	{
		free (data->img);
		free (data);
		return (NULL);
	}
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	data->img->pimg = (uint8_t *)data->img->addr;
	return (data);
}

void	free_textures(t_cube *cube, t_axpm *texture)
{
	if (texture->no)
	{
		mlx_destroy_image(cube->mlx->mlx_ptr, texture->no->img->mlx_img);
		free (texture->no->img);
		free (texture->no);
	}
	if (texture->so)
	{
		mlx_destroy_image(cube->mlx->mlx_ptr, texture->so->img->mlx_img);
		free (texture->so->img);
		free (texture->so);
	}
	if (texture->ea)
	{
		mlx_destroy_image(cube->mlx->mlx_ptr, texture->ea->img->mlx_img);
		free (texture->ea->img);
		free (texture->ea);
	}
	if (texture->we)
	{
		mlx_destroy_image(cube->mlx->mlx_ptr, texture->we->img->mlx_img);
		free (texture->we->img);
		free (texture->we);
	}
	free (texture);
}

int	check_textures(t_cube *cube, t_axpm *texture)
{
	if (!texture->no || !texture->so || !texture->we || !texture->ea)
	{
		free_textures(cube, texture);
		return (1);
	}
	return (0);
}

t_axpm	*init_texture(t_cube *cube)
{
	t_axpm	*texture;

	texture = malloc(sizeof(t_axpm));
	if (!texture)
		exit (EXIT_FAILURE);
	texture->no = init_tdata(cube, cube->map->NO);
	texture->so = init_tdata(cube, cube->map->SO);
	texture->ea = init_tdata(cube, cube->map->EA);
	texture->we = init_tdata(cube, cube->map->WE);
	if (check_textures(cube, texture) == 1)
		return (NULL);
	return (texture);
}
