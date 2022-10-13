/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:52:10 by avillar           #+#    #+#             */
/*   Updated: 2022/09/15 10:01:52 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	manage_error(char c, char *str, int mode)
{
	if (mode == 0)
	{
		free (str);
		printf("Error\n%c is not an authorised identifier\n", c);
	}
	else if (mode == 1)
		printf("Error\nunexpected identifier near %c in file .cub\n", c);
	return (1);
}

int	manager(int fd, char c, t_cube *cube, char *str)
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
		return (manage_error(c, str, 0));
}

int	check_if_set(t_cube *cube)
{
	if (ccc && cno && cso && cea && cwe && cfc)
		return (0);
	else
		return (1);
}
