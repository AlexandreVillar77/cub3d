/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:57:36 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/02 09:40:27 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	handle_error_parsing_map(int i)
{
	if (i == 6)
		printf("Not enought line for the map\n");
	else if (i == 7)
		printf("Problem in the map\n");
	else if (i == 8)
		printf("Player is missing\n");
	else if (i == 9)
		printf("Too many player\n");
	else if (i == 10)
		printf("Strange symbol found in the map\n");
	else if (i == 11)
		printf("wrong name for texture\n");
	else if (i == 12)
		printf("Map not found\n");
	return (1);
}

int	handle_error(int i)
{
	printf("Error\n");
	if (i == 1)
		printf("Usage: \"./cub3d\" \"name of a map\".cub\n");
	else if (i == 2)
		printf("Wrong map name, use: \"name of a map\".cub\n");
	else if (i == 3)
		printf("Cannot access the map, pls check permission or map existing\n");
	else if (i == 4)
		printf("Cannot access texture, check permission or texture existing\n");
	else if (i == 5)
		printf("Wrong number use for Floor or Ceiling in the map\n");
	else
		return (handle_error_parsing_map(i));
	return (1);
}
