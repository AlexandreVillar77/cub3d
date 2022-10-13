/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:11:44 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/16 09:44:22 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*remove_rtnl(char *src)
{
	int		i;
	char	*rtn;
	int		len;

	if (!src)
		return (NULL);
	if (ft_strlen(src) < 1)
		return (src);
	len = ft_strlen(src);
	i = 0;
	if (src[len - 1] != '\n')
		return (src);
	rtn = malloc(sizeof(char) * (len));
	while (i < len - 1)
	{
		rtn[i] = src[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*add_one_char(char *src, int toadd, char c)
{
	int		i;
	int		x;
	char	*dest;

	if (!src)
	{
		src = malloc(sizeof(char) * 1);
		src[0] = '\0';
		x = 0;
	}
	else
		x = ft_strlen(src);
	i = 0;
	dest = malloc(sizeof(char) * (x + 2));
	if (!dest || !src)
		exit (EXIT_FAILURE);
	while (i < x && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = c;
	dest[++i] = '\0';
	free(src);
	return (dest);
}

int		get_tab_ylen(char **str, t_cube *cube)
{
	int	i;
	int	x;
	
	if (!str)
		return (0);
	x = 0;
	i = 0;
	while (str[i])
	{
		x = 0;
		while (str[i][x])
			x++;
		if (x > cube->largestl)
			cube->largestl = x;
		i++;
	}return (i);
}

void	tab_xy(t_cube *cube)
{
	int	i;

	if (!cmap)
		return ;
	cube->mapls = malloc(sizeof(int) * (cube->nline + 1));
	if (!cube->mapls)
		return ;
	i = 0;

	while (i < cube->nline - 1)
	{
		cube->mapls[i] = ft_strlen(cmap[i]);
		i++;
	}
	cube->mapls[i] = 0;
}
