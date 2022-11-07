/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:52:05 by avillar           #+#    #+#             */
/*   Updated: 2022/11/03 14:10:41 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strnew(size_t size)
{
	char		*s;
	size_t		i;

	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (0);
	if ((size + 1) > 0)
	{
		i = 0;
		while (i < (size + 1))
		{
			s[i] = 0;
			i++;
		}
	}
	return (s);
}

char	**free_memory(char **memory, char *tmp)
{
	free(memory[0]);
	memory[0] = tmp;
	if (*memory[0] == 0)
	{
		free(memory[0]);
		memory[0] = NULL;
	}
	return (memory);
}

char	*alloc_read(char **memory, int fd, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(memory[fd], buffer);
	if (!tmp)
		return (NULL);
	free(memory[fd]);
	memory[fd] = tmp;
	return (memory[fd]);
}
