/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cardi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:49:07 by avillar           #+#    #+#             */
/*   Updated: 2022/11/02 14:09:46 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_if_right(int fd, char *expected)
{
	int		i;
	int		x;
	char	buf;

	x = 1;
	i = 0;
	buf = 'q';
	while (x > 0 && i < ft_strlen(expected))
	{
		x = read(fd, &buf, 1);
		if (x < 0)
			return (1);
		if (buf != expected[i])
			return (1);
		i++;
	}
	return (0);
}

int	parse_no(int fd, t_cube *cube)
{
	char	buf;
	int		i;

	if (check_if_right(fd, "O ") == 1 || check_double(cube, 0) == 1)
		return (manage_error('N', 1, cube));
	i = 1;
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || check_for_wp(buf) == 0)
			break ;
	}
	if (i > 0)
		cube->map->no = add_one_char(cube->map->no, buf);
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || buf == '\n')
			break ;
		cube->map->no = add_one_char(cube->map->no, buf);
	}
	return (0);
}

int	parse_so(int fd, t_cube *cube)
{
	char	buf;
	int		i;

	if (check_if_right(fd, "O ") == 1 || check_double(cube, 1) == 1)
		return (manage_error('S', 1, cube));
	i = 1;
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || check_for_wp(buf) == 0)
			break ;
	}
	if (i > 0)
		cube->map->so = add_one_char(cube->map->so, buf);
	while (buf != '\n' && i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || buf == '\n')
			break ;
		cube->map->so = add_one_char(cube->map->so, buf);
	}
	return (0);
}

int	parse_ea(int fd, t_cube *cube)
{
	char	buf;
	int		i;

	if (check_if_right(fd, "A ") == 1 || check_double(cube, 2) == 1)
		return (manage_error('E', 1, cube));
	i = 1;
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || check_for_wp(buf) == 0)
			break ;
	}
	if (i > 0)
		cube->map->ea = add_one_char(cube->map->ea, buf);
	while (buf != '\n' && i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || buf == '\n')
			break ;
		cube->map->ea = add_one_char(cube->map->ea, buf);
	}
	return (0);
}

int	parse_we(int fd, t_cube *cube)
{
	char	buf;
	int		i;

	if (check_if_right(fd, "E ") == 1 || check_double(cube, 3) == 1)
		return (manage_error('W', 1, cube));
	i = 1;
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || check_for_wp(buf) == 0)
			break ;
	}
	if (i > 0)
		cube->map->we = add_one_char(cube->map->we, buf);
	while (buf != '\n' && i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || buf == '\n')
			break ;
		cube->map->we = add_one_char(cube->map->we, buf);
	}
	return (0);
}
