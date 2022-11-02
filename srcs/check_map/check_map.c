/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:32:31 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/02 09:44:37 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_around(char **map, int i, int y)
{
	if (map[i][y + 1] != '0' && map[i][y + 1] != '1'
		&& map[i][y + 1] != 'N'
		&& map[i][y + 1] != 'S' && map[i][y + 1] != 'E'
		&& map[i][y + 1] != 'W')
		return (handle_error(7));
	if (map[i][y - 1] != '0' && map[i][y - 1] != '1'
		&& map[i][y - 1] != 'N'
		&& map[i][y - 1] != 'S' && map[i][y - 1] != 'E'
		&& map[i][y - 1] != 'W')
		return (handle_error(7));
	if (map[i - 1][y] != '0' && map[i - 1][y] != '1'
		&& map[i - 1][y] != 'N'
		&& map[i - 1][y] != 'S' && map[i - 1][y] != 'E'
		&& map[i - 1][y] != 'W')
		return (handle_error(7));
	return (look_around(map, i, y));
}

int	check_top_bot(char **map, int y)
{
	int	i;

	i = 0;
	while (map[y][i])
	{
		if (map[y][i] != ' ' && map[y][i] != '1')
			return (handle_error(7));
		i++;
	}
	return (0);
}

int	check_middle_2(char **map, int *player, int i, int y)
{
	y = 0;
	while (map[i][y])
	{
		while (map[i][y] == ' ')
			y++;
		if (map[i][y] == '0')
		{
			if (check_around(map, i, y) == 1)
				return (1);
		}
		else if (map[i][y] == 'N' || map[i][y] == 'S'
			|| map[i][y] == 'E' || map[i][y] == 'W')
		{
			if (check_around(map, i, y) == 1)
				return (1);
			*player = *player + 1;
		}
		else if (map[i][y] != ' ' && map[i][y] != '1')
			return (handle_error(10));
		y++;
	}
	return (0);
}

int	check_middle(char **map, int *player)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map[i + 1])
	{
		if (check_middle_2(map, player, i, y) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_map(t_map *map)
{
	int	player;
	int	i;

	if (!map->map)
		return (handle_error(12));
	player = 0;
	while (map->map[player])
		player++;
	if (player <= 2)
		return (handle_error(6));
	player = 0;
	if (check_top_bot(map->map, 0) == 1 || check_middle(map->map, &player) == 1)
		return (1);
	i = 0;
	while (map->map[i])
		i++;
	if (check_top_bot(map->map, --i) == 1)
		return (1);
	return (print_error_player(player));
}
