/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:54:55 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/02 11:38:30 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_map(t_cube *cube)
{
	int	i;

	i = 0;
	printf("NO = %s\n", cube->map->no);
	printf("WE = %s\n", cube->map->we);
	printf("EA = %s\n", cube->map->ea);
	printf("SO = %s\n", cube->map->so);
	if (!cube->map->map)
		return ;
	while (cube->map->map[i])
	{
		printf("%s\n", cube->map->map[i]);
		i++;
	}
	i = 0;
	printf("nlone = %d\n", cube->nline);
	while (i < cube->nline - 1)
	{
		printf("line %d size = %d\n", i, cube->mapls[i]);
		i++;
	}
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
