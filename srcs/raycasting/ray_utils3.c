/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:19:58 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/02 10:22:45 by thbierne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	modif_x_y(t_ray *ray)
{
	ray->dist_x += (double)ray->pdx;
	ray->dist_y += (double)ray->pdy;
	ray->x += (double)ray->pdx;
	ray->y += (double)ray->pdy;
}
