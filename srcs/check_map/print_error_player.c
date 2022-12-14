/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:40:06 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/02 09:49:53 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	print_error_player(int player)
{
	if (player == 0 || player >= 2)
	{
		if (player == 0)
			return (handle_error(8));
		else
			return (handle_error(9));
	}
	return (0);
}
