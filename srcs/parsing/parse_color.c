/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:12:30 by avillar           #+#    #+#             */
/*   Updated: 2022/09/15 09:46:42 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

int	parse_fc(int fd, t_cube *cube)
{
	char	buf;
	int		i;

	if (check_if_right(fd, " ") == 1)
		return (manage_error('F', NULL, 1));
	i = 1;
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || check_for_wp(buf) == 0)
			break ;
	}
	if (i > 0)
		cfc = add_one_char(cfc, 1, buf);
	while (buf != '\n' && i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || buf == '\n')
			break ;
		cfc = add_one_char(cfc, 1, buf);
	}
	return (0);
}

int	parse_cellcolor(int fd, t_cube *cube)
{
	char	buf;
	int		i;

	if (check_if_right(fd, " ") == 1)
		return (manage_error('C', NULL, 1));
	i = 1;
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || check_for_wp(buf) == 0)
			break ;
	}
	if (i > 0)
		ccc = add_one_char(ccc, 1, buf);
	while (buf != '\n' && i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || buf == '\n')
			break ;
		ccc = add_one_char(ccc, 1, buf);
	}
	return (0);
}
