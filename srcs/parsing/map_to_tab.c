/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:20:18 by avillar           #+#    #+#             */
/*   Updated: 2022/10/21 11:24:56 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_for_wp(char c)
{
	if (c == '\t' || c == '\r' || c == '\v' || c == '\n' || c == ' '
		|| c == '\f')
		return (1);
	else
		return (0);
}

char	*reset_rtn(char *rtn)
{
	free (rtn);
	rtn = malloc(sizeof(char));
	rtn[0] = '\0';
	return (rtn);
}

char	*skip(int fd)
{
	int		x;
	char	buf;
	char	*rtn;

	x = 1;
	rtn = malloc(sizeof(char));
	while (x > 0)
	{
		x = read(fd, &buf, 1);
		if (x < 1)
		{
			free (rtn);
			return (NULL);
		}
		if (buf == '\n')
			rtn = reset_rtn(rtn);
		else
			rtn = add_one_char(rtn, buf);
		if (buf == '1')
			break ;
	}
	return (rtn);
}

// mettre fonction pour free rtn   + keep;

char	*map_to_str(int fd)
{
	int		x;
	char	buf;
	char	*rtn;

	rtn = skip(fd);
	x = 1;
	while (x > 0)
	{
		x = read(fd, &buf, 1);
		if (x < 0)
			return (NULL);
		if (x > 0)
			rtn = add_one_char(rtn, buf);
	}
	return (rtn);
}

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
	cube->nline = get_tab_ylen(cmap, cube);
	//alloc_size_texture(cube);
	return (0);
}

int	get_largest_l(char **map)
{
	int	i;
	int	y;
	int max;

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

char **put_space(char **map, int l, int n)
{
	int	y;
	int	i;
	char **dest;

	y = 0;
	dest = NULL;
	dest = malloc_lines(dest, l, n);
	while (y < n)
	{
		i = 0;
		while (map[y][i] && map[y][i] != '\n')
		{
			dest[y][i] = map[y][i];
			i++;
		}
		if (i < l)
		{
			while (i < l - 1)
			{
				dest[y][i] = ' ';
				i++;
			}
			dest[y][i - 1] = '\n';
			dest[y][i] = '\0'; 
		}
		y++;
	}
	dest[y] = 0;
	//free(map);
	return (dest);
}
