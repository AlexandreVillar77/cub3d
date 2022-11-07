/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:52:10 by avillar           #+#    #+#             */
/*   Updated: 2022/11/03 14:44:12 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	manage_error(char c, int mode, t_cube *cube)
{
	(void)c;
	if (mode == 1)
	{
		cube->map->error = 1;
		printf("Error\nWrong parameters on textures\n");
		free_cube(cube);
		exit (EXIT_FAILURE);
	}
	else if (mode == 2)
	{
		cube->map->error = 2;
		printf("Error\nWrong parameters on color\n");
		free_cube(cube);
		exit (EXIT_FAILURE);
	}
	return (1);
}

int	manager(int fd, char c, t_cube *cube)
{
	if (c == 'N')
		return (parse_no(fd, cube));
	else if (c == 'S')
		return (parse_so(fd, cube));
	else if (c == 'E')
		return (parse_ea(fd, cube));
	else if (c == 'W')
		return (parse_we(fd, cube));
	else if (c == 'F')
		return (parse_fc(fd, cube));
	else if (c == 'C')
		return (parse_cellcolor(fd, cube));
	else
		return (manage_error(c, 0, cube));
}

int	check_if_set(t_cube *cube)
{
	if (cube->map->cellcolor && cube->map->no && cube->map->so
		&& cube->map->ea && cube->map->we && cube->map->fcolor)
		return (0);
	else
		return (1);
}
