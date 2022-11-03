/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:52:05 by avillar           #+#    #+#             */
/*   Updated: 2022/11/03 11:43:40 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *src, char *tmp)
{
	int		i;
	int		x;
	char	*dst;

	i = 0;
	x = 0;
	dst = malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(src) + 1));
	if (!dst)
		return (0);
	while (tmp[i])
	{
		dst[i] = tmp[i];
		i++;
	}
	while (src[x])
	{
		dst[i] = src[x];
		x++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*checkbuf(char *buf, char *keep)
{
	char	*tmp;

	if (!keep)
	{
		keep = malloc(sizeof(char) * 1);
		if (!keep)
			return (0);
		keep[0] = '\0';
	}
	tmp = ft_strcpy(keep);
	free(keep);
	keep = ft_strjoin(buf, tmp);
	free(tmp);
	return (keep);
}

char	*putline(char *keep)
{
	int		i;
	char	*dst;
	int		x;

	i = 0;
	x = ft_linelen(keep);
	/*if (x == 0)
	{
		dst = malloc(sizeof(char) * (2));
		dst[0] = ' ';
		dst[1] = '\0';
		return (dst);
	}*/
	dst = malloc(sizeof(char) * (x + 1));
	if (!dst)
		return (0);
	while (keep[i] != '\n' && keep[i] != '\0')
	{
		dst[i] = keep[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}