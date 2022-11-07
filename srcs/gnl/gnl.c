/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:52:11 by avillar           #+#    #+#             */
/*   Updated: 2022/11/03 14:10:47 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	no_leaks(char **line, char **memory, char *buffer, int ret)
{
	if (ret == -2)
		return (-1);
	if (*line && line[0] == 0 && ret == -1)
		free(*line);
	if ((*memory == 0 && memory[0] != NULL) || ret != 1)
	{
		free(memory[0]);
		memory[0] = NULL;
	}
	if (buffer)
		free(buffer);
	return (ret);
}

int	creat_line(char **line, char **memory)
{
	int		i;
	char	*tmp;

	i = 0;
	while (memory[0][i] != '\n' && memory[0][i])
		i++;
	if (memory[0][i] == '\n')
	{
		memory[0][i] = '\0';
		*line = ft_strdup(memory[0]);
		if (!(*line))
			return (-1);
		tmp = ft_strdup(&memory[0][i + 1]);
		if (!tmp)
			return (-1);
		memory = free_memory(memory, tmp);
	}
	else if (1)
	{
		*line = ft_strdup(memory[0]);
		if (!(*line))
			return (-1);
	}
	return (1);
}

int	check_return(char **line, char **memory, int read_char, char *buffer)
{
	int	ret;

	if (read_char < 0)
		return (no_leaks(line, &memory[0], buffer, -1));
	else if (read_char == 0 && *memory == 0)
	{
		*line = ft_strdup("\0");
		if (!(*line))
			return (no_leaks(line, &memory[0], buffer, -1));
		return (no_leaks(line, &memory[0], buffer, 0));
	}
	else if (read_char == 0 && (!ft_strchr(memory[0], '\n')))
	{
		*line = ft_strdup(memory[0]);
		if (!(*line))
			return (no_leaks(line, &memory[0], buffer, -1));
		return (no_leaks(line, &memory[0], buffer, 0));
	}
	ret = creat_line(line, memory);
	return (no_leaks(line, &memory[0], buffer, ret));
}

int	get_next_line(int fd, char **line)
{
	static char		*memory[8192];
	char			*buffer;
	int				read_char;

	buffer = ft_strnew(1000);
	if (!buffer)
		return (no_leaks(line, &memory[fd], buffer, -1));
	if ((1000 <= 0) || (line == NULL) || (fd < 0))
		return (no_leaks(line, &memory[fd], buffer, -2));
	read_char = read(fd, buffer, 1000);
	while (read_char > 0)
	{
		buffer[read_char] = '\0';
		if (memory[fd] == NULL)
			memory[fd] = ft_strdup(buffer);
		else
			memory[fd] = alloc_read(memory, fd, buffer);
		if (ft_strchr(memory[fd], '\n'))
			break ;
		read_char = read(fd, buffer, 1000);
	}
	return (check_return(line, &memory[fd], read_char, buffer));
}
