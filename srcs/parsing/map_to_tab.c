/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:20:18 by avillar           #+#    #+#             */
/*   Updated: 2022/11/02 10:53:25 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// mettre fonction pour free rtn   + keep;

int	read_keep(int fd, t_cube *cube)
{
	char	buf;
	int		j;
	char	*str;

	j = 1;
	while (j > 0)
	{
		j = read(fd, &buf, 1);
		if (j == -1)
			return (-1);
		if (check_for_wp(buf) == 0)
			if (manager(fd, buf, cube) == 1)
				return (1);
		if (check_if_set(cube) == 0)
			break ;
	}
	str = map_to_str(fd);
	cube->map->map = ft_split(str, '\n');
	if (str)
		free (str);
	cube->nline = get_tab_ylen(cube->map->map, cube);
	tab_xy(cube);
	close(fd);
	return (0);
}

int	get_largest_l(char **map)
{
	int	i;
	int	y;
	int	max;

	y = 0;
	max = 0;
	while (map[y])
	{
		if (i > max)
			max = i;
		i = 0;
		while (map[y][i])
			i++;
		y++;
	}
	return (max);
}

int	get_n_line(char **map)
{
	int	i;
	int	y;

	y = 0;
	while (map[y])
	{
		i = 0;
		while (map[y][i])
			i++;
		y++;
	}
	return (y);
}

char	**malloc_lines(char **dest, int l, int n)
{
	int	y;

	y = 0;
	dest = malloc(sizeof(char *) * (n + 1));
	if (!dest)
		exit(EXIT_FAILURE);
	while (y < n)
	{
		dest[y] = malloc(sizeof(char) * (l + 2));
		y++;
	}
	return (dest);
}
