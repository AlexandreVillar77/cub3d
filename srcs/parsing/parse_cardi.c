/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cardi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:49:07 by avillar           #+#    #+#             */
/*   Updated: 2022/10/21 11:26:05 by avillar          ###   ########.fr       */
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

	if (check_if_right(fd, "O ") == 1)
		return (manage_error('N', 1));
	i = 1;
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || check_for_wp(buf) == 0)
			break ;
	}
	if (i > 0)
		cno = add_one_char(cno, buf);
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || buf == '\n')
			break ;
		cno = add_one_char(cno, buf);
	}
	return (0);
}

int	parse_so(int fd, t_cube *cube)
{
	char	buf;
	int		i;

	if (check_if_right(fd, "O ") == 1)
		return (manage_error('S', 1));
	i = 1;
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || check_for_wp(buf) == 0)
			break ;
	}
	if (i > 0)
		cso = add_one_char(cso, buf);
	while (buf != '\n' && i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || buf == '\n')
			break ;
		cso = add_one_char(cso, buf);
	}
	return (0);
}

int	parse_ea(int fd, t_cube *cube)
{
	char	buf;
	int		i;

	if (check_if_right(fd, "A ") == 1)
		return (manage_error('E', 1));
	i = 1;
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || check_for_wp(buf) == 0)
			break ;
	}
	if (i > 0)
		cea = add_one_char(cea, buf);
	while (buf != '\n' && i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || buf == '\n')
			break ;
		cea = add_one_char(cea, buf);
	}
	return (0);
}

int	parse_we(int fd, t_cube *cube)
{
	char	buf;
	int		i;

	if (check_if_right(fd, "E ") == 1)
		return (manage_error('W', 1));
	i = 1;
	while (i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || check_for_wp(buf) == 0)
			break ;
	}
	if (i > 0)
		cwe = add_one_char(cwe, buf);
	while (buf != '\n' && i > 0)
	{
		i = read(fd, &buf, 1);
		if (i <= 0 || buf == '\n')
			break ;
		cwe = add_one_char(cwe, buf);
	}
	return (0);
}
