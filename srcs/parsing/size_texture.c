/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:55:52 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/03 11:42:34 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

/*
	x = read(fd, &buf, 1);
	if (x < 0)
		return (NULL);
	if (x > 0)
		rtn = add_one_char(rtn, buf);
*/

char	*map_to_str(int fd)
{
	int		x;
	char	*rtn;
	char	*line;
	char	*tmp;

	rtn = skip(fd);
	line = NULL;
	x = get_next_line(fd, &line);
	while (x > 0)
	{
		tmp = ft_strjoin(rtn, line);
		free (rtn);
		rtn = ft_strjoin(tmp, "\n");
		free (tmp);
		free (line);
		x = get_next_line(fd, &line);
	}
	if (line)
	{
		tmp = ft_strjoin(rtn, line);
		free (rtn);
		rtn = ft_strjoin(tmp, "\n");
		free (tmp);
		free (line);
	}
	printf("%s\n", rtn);
	return (rtn);
}
