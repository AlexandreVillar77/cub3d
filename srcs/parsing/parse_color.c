/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:12:30 by avillar           #+#    #+#             */
/*   Updated: 2022/11/02 14:08:57 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_double(t_cube *cube, int n)
{
	if (n == 0)
		if (cube->map->no)
			return (1);
	if (n == 1)
		if (cube->map->so)
			return (1);
	if (n == 2)
		if (cube->map->ea)
			return (1);
	if (n == 3)
		if (cube->map->we)
			return (1);
	if (n == 4)
		if (cube->map->fcolor)
			return (1);
	if (n == 5)
		if (cube->map->cellcolor)
			return (1);
	return (0);
}

char	s_wp(int fd)
{
	int		x;
	char	buf;

	x = read(fd, &buf, 1);
	if (x < 0)
		return (0);
	while (check_for_wp(buf) == 1 && x > 0)
	{
		x = read(fd, &buf, 1);
		if (x < 0)
			return (0);
	}
	return (buf);
}

char	*malloc_and_set(int i, char c)
{
	char	*str;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	if (i > 0)
		str = add_one_char(str, c);
	return (str);
}

int	parse_fc(int fd, t_cube *cube)
{
	char	buf;
	int		i;
	char	*cfc;

	if (check_if_right(fd, " ") == 1 || check_double(cube, 4) == 1)
		return (manage_error('F', 2, cube));
	i = 1;
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || check_for_wp(buf) == 0)
			break ;
	}
	cfc = malloc_and_set(i, buf);
	while (buf != '\n' && i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || buf == '\n')
			break ;
		cfc = add_one_char(cfc, buf);
	}
	cube->map->fcolor = ft_split(cfc, ',');
	free (cfc);
	return (0);
}

int	parse_cellcolor(int fd, t_cube *cube)
{
	char	buf;
	int		i;
	char	*ccc;

	if (check_if_right(fd, " ") == 1 || check_double(cube, 5) == 1)
		return (manage_error('C', 2, cube));
	i = 1;
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || check_for_wp(buf) == 0)
			break ;
	}
	ccc = malloc_and_set(i, buf);
	while (buf != '\n' && i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || buf == '\n')
			break ;
		ccc = add_one_char(ccc, buf);
	}
	cube->map->cellcolor = ft_split(ccc, ',');
	free (ccc);
	return (0);
}
