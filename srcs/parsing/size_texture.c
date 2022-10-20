/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:55:52 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/20 14:22:34 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	alloc_size_texture(t_cube *cube)
{
	get_size(cube, cube->map->NO, 1);
	get_size(cube, cube->map->NO, 2);
	get_size(cube, cube->map->NO, 3);
	get_size(cube, cube->map->NO, 4);
}

void	get_size(t_cube *cube, char *file, int i)
{
	char	*str;

	str = malloc(sizeof(char));
	str[0] = '\0';
	pos_size();
	if (i == 1)
	{

	}
}