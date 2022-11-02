/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:49:27 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/02 11:32:24 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_xpm(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (--i < 4)
		return (handle_error(11));
	if (str[i] != 'm' || str[i - 1] != 'p' || str[i - 2] != 'x'
		|| str[i - 3] != '.')
		return (handle_error(11));
	if (str[i - 4] == '.')
		return (handle_error(11));
	return (0);
}

int	set_xpm(t_map *map)
{
	if (check_xpm(map->no) == 1)
		return (1);
	if (check_xpm(map->ea) == 1)
		return (1);
	if (check_xpm(map->so) == 1)
		return (1);
	if (check_xpm(map->we) == 1)
		return (1);
	return (0);
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
	if (!split)
		return (1);
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

	if (!map->no || !map->so || !map->we || !map->ea
		|| access(map->no, R_OK) == -1 || access(map->so, R_OK) == -1
		|| access(map->we, R_OK) == -1 || access(map->ea, R_OK) == -1)
		return (handle_error(4));
	i = -1;
	while (++i < 2)
	{
		if (i == 0)
			split = map->cellcolor;
		else
			split = map->fcolor;
		if (check_floor_cell(split) == 1)
			return (handle_error(5));
	}
	if (set_xpm(map) == 1)
		return (1);
	return (0);
}
