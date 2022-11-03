/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:52:11 by avillar           #+#    #+#             */
/*   Updated: 2022/11/03 11:46:46 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*cleankeep(char *keep, int len)
{
	int		i;
	char	*tmp;

	i = 0;
	if (len <= 1)
		return (NULL);
	if (ft_strlen(keep) == len)
	{
		free(keep);
		return (NULL);
	}
	if (keep[len] == '\n')
		len++;
	tmp = malloc(sizeof(char) * ((ft_strlen(keep) - len) + 2));
	if (!tmp)
		return (0);
	while (keep[i + len])
	{
		tmp[i] = keep[i + len];
		i++;
	}
	tmp[i] = '\0';
	free(keep);
	return (tmp);
}

int		ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

int		is_line(char *keep)
{
	int		i;

	i = 0;
	if (keep)
	{
		while (keep[i] != '\n' && keep[i] != '\0')
			i++;
		if (keep[i] == '\n')
			return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	int			x;
	static char	*keep;

	x = 1;
	buf = malloc(100 + 1);
	if (fd < 0 || !line || 100 <= 0 || !buf)
		return (-1);
	while (is_line(keep) == 0 && x != 0)
	{
		x = read(fd, buf, 100);
		if (x == -1)
		{
			free(buf);
			return (-1);
		}
		buf[x] = '\0';
		keep = checkbuf(buf, keep);
	}
	free(buf);
	*line = putline(keep);
	keep = cleankeep(keep, ft_strlen(*line));
	if (x == 0)
		return (0);
	return (1);
}