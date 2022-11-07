/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:05:39 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/04 09:46:55 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_cub(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (i-- <= 4)
		return (1);
	if (argv[i] != 'b' || argv[i - 1] != 'u'
		|| argv[i - 2] != 'c' || argv[i - 3] != '.')
		return (1);
	else if (i >= 4 && argv[i] == 'b' && argv[i - 1] == 'u'
		&& argv[i - 2] == 'c' && argv[i - 3] == '.'
		&& argv[i - 4] == '.')
		return (1);
	else if (i >= 4 && argv[i] == 'b' && argv[i - 1] == 'u'
		&& argv[i - 2] == 'c' && argv[i - 3] == '.'
		&& argv[i - 4] == '/')
		return (1);
	return (0);
}

int	check_arg(int argc, char **argv)
{
	if (argc != 2)
		return (handle_error(1));
	if (check_cub(argv[1]) == 1)
		return (handle_error(2));
	if (access(argv[1], R_OK) != 0)
		return (handle_error(3));
	return (0);
}

int	check_access(t_map *map)
{
	if (access(map->no, R_OK) == -1 || access(map->so, R_OK) == -1
		|| access(map->we, R_OK) == -1 || access(map->ea, R_OK) == -1)
		return (handle_error(4));
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
