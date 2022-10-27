/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_around.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:44:30 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/24 10:32:30 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	look_around2(char **map, int i, int y)
{
	if (map[i - 1][y - 1] != '0' && map[i - 1][y - 1] != '1'
		&& map[i - 1][y - 1] != 'N'
		&& map[i - 1][y - 1] != 'S' && map[i - 1][y - 1] != 'E'
		&& map[i - 1][y - 1] != 'W')
	{
		handle_error(7);
		return (1);
	}
	if (map[i + 1][y - 1] != '0' && map[i + 1][y - 1] != '1'
		&& map[i + 1][y - 1] != 'N'
		&& map[i + 1][y - 1] != 'S' && map[i + 1][y - 1] != 'E'
		&& map[i + 1][y - 1] != 'W')
	{
		handle_error(7);
		return (1);
	}
	return (0);
}

int	look_around(char **map, int i, int y)
{
	if (map[i + 1][y] != '0' && map[i + 1][y] != '1'
		&& map[i + 1][y] != 'N'
		&& map[i + 1][y] != 'S' && map[i + 1][y] != 'E'
		&& map[i + 1][y] != 'W')
	{
		handle_error(7);
		return (1);
	}
	if (map[i + 1][y + 1] != '0' && map[i + 1][y + 1] != '1'
		&& map[i + 1][y + 1] != 'N'
		&& map[i + 1][y + 1] != 'S' && map[i + 1][y + 1] != 'E'
		&& map[i + 1][y + 1] != 'W')
	{
		handle_error(7);
		return (1);
	}
	if (map[i - 1][y + 1] != '0' && map[i - 1][y + 1] != '1'
		&& map[i - 1][y + 1] != 'N'
		&& map[i - 1][y + 1] != 'S' && map[i - 1][y + 1] != 'E'
		&& map[i - 1][y + 1] != 'W')
	{
		handle_error(7);
		return (1);
	}
	return (look_around2(map, i, y));
}
