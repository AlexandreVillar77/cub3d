/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:05:39 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/20 17:42:30 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_cub(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (i-- <= 4)
		return (1);
	if (argv[i] != 'b' || argv[i - 1] != 'u'
		|| argv[i - 2] != 'c' || argv[i - 3] != '.')
		return (1);
	return (0);
}

int	check_arg(int argc, char **argv)
{

	if (argc != 2)
	{
		handle_error(1);
		return (1);
	}
	if (check_cub(argv[1]) == 1)
	{
		handle_error(2);
		return (1);
	}
	if (access(argv[1], R_OK) != 0)
	{
		handle_error(3);
		return (1);
	}
	return (0);
}
