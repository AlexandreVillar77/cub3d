/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:05:39 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/15 09:28:57 by thbierne         ###   ########.fr       */
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
	int	i;

	if (argc != 2)
	{
		handle_error(1);
		return (1);
	}
	i = ft_strlen(argv[1]);
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
