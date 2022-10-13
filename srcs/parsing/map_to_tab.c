/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:20:18 by avillar           #+#    #+#             */
/*   Updated: 2022/09/16 09:43:39 by avillar          ###   ########.fr       */
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
	int		i;
	int		x;
	char	buf;
	char	*rtn;

	i = 0;
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
			rtn = add_one_char(rtn, 1, buf);
		if (buf == '1')
			break ;
	}
	return (rtn);
}

// mettre fonction pour free rtn   + keep;

char	*map_to_str(int fd)
{
	int		i;
	int		x;
	char	buf;
	char	*rtn;
	char	*keep;

	rtn = skip(fd);
	i = 0;
	x = 1;
	while (x > 0)
	{
		x = read(fd, &buf, 1);
		if (x < 0)
			return (NULL);
		if (x > 0)
			rtn = add_one_char(rtn, 1, buf);
	}
	return (rtn);
}

int	read_keep(int fd, char **tab, int x, t_cube *cube)
{
	char	buf;
	int		j;
	char	*str;

	j = 1;
	str = malloc(sizeof(char));
	str[0] = '\0';
	while (j > 0)
	{
		j = read(fd, &buf, 1);
		if (j == -1)
			return (-1);
		if (check_for_wp(buf) == 0)
			if (manager(fd, buf, cube, str) == 1)
				return (1);
		if (check_if_set(cube) == 0)
			break ;
	}
	str = map_to_str(fd);
	cube->map->map = ft_split(str, '\n');
	if (str)
		free (str);
	cube->nline = get_tab_ylen(cmap, cube);
	return (0);
}
