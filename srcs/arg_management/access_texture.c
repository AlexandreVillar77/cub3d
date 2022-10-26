/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:49:27 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/26 10:36:23 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int check_xpm(char *str)
{
	int i;

	i = ft_strlen(str);
	if (--i < 4)
	{
		handle_error(11);
		return (1);
	}
	if (str[i] != 'm' || str[i - 1] != 'p' || str[i - 2] != 'x'
		|| str[i - 3] != '.')
	{
		handle_error(11);
		return (1);
	}
	if (str[i - 4] == '.')
	{
		handle_error(11);
		return (1);
	}
	return (0);
}

int	set_xpm(t_map *map)
{
	if (check_xpm(map->NO) == 1)
		return (1);
	if (check_xpm(map->EA) == 1)
		return (1);
	if (check_xpm(map->SO) == 1)
		return (1);
	if (check_xpm(map->WE) == 1)
		return (1);
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free (split);
}

int	check_floor_cell_var(char **split)
{
	int	i;
	int	nbr;

	i = -1;
	while (++i < 3)
	{
		nbr = ft_atoi(split[i]);
		if (nbr < 0 || nbr > 255)
			return (1);
	}
	return (0);
}

int	check_floor_cell(char **split)
{
	int	i;
	int	y;

	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		return (1);
	i = -1;
	while (split[++i])
	{
		y = -1;
		while (split[i][++y])
		{
			if (split[i][y] < '0' || split[i][y] > '9')
				return (1);
		}
	}
	if (check_floor_cell_var(split) == 1)
		return (1);
	return (0);
}

int	access_texture(t_map *map)
{
	char	**split;
	int		i;

	if (access(map->NO, R_OK) == -1 || access(map->SO, R_OK) == -1
		|| access(map->WE, R_OK) == -1 || access(map->EA, R_OK) == -1)
	{
		handle_error(4);
		return (1);
	}
	i = -1;
	while (++i < 2)
	{
		if (i == 0)
			split = map->Cellcolor;
		else
			split = map->Fcolor;
		if (check_floor_cell(split) == 1)
		{
			handle_error(5);
			return (1);
		}
	}
	if (set_xpm(map) == 1)
		return (1);
	return (0);
}
