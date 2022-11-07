/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:55:52 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/04 09:38:21 by thbierne         ###   ########.fr       */
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
	rtn[0] = '\0';
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

char	*jon(char *dest, char *line)
{
	char	*tmp;

	if (line[0] == '\0')
	{
		tmp = ft_strjoin(dest, " \n");
		free (dest);
		dest = ft_strcpy(tmp);
		free (tmp);
		free (line);
	}
	else
	{
		tmp = ft_strjoin(dest, line);
		free (dest);
		dest = ft_strjoin(tmp, "\n");
		free (tmp);
		free (line);
	}
	return (dest);
}

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
		rtn = jon(rtn, line);
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
	return (rtn);
}
