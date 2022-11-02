/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:25:24 by avillar           #+#    #+#             */
/*   Updated: 2022/11/02 11:09:20 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// fov = 60 degre
// taille fenetre 600 * 600
// donc incrementation de  l'angle = fov / taille fenetre

t_ddd	*init_ddd(t_cube *cube)
{
	t_ddd	*dd;

	dd = malloc(sizeof(t_ddd));
	dd->winw = DDWIN_S;
	dd->winh = DDWIN_S;
	dd->index = 0;
	dd->win_ptr = mlx_new_window(cube->mlx->mlx_ptr,
			dd->winw, dd->winh, "3d test");
	dd->backg = NULL;
	return (dd);
}

/*
pour taille mur texture produit en croix avec taille max mur 
soit taille de la fenetre donc

DDWIN_S * distance a laquelle le mur fait 
sa taille max / la taille du rayon

donc faire attention a afficher les pixels que s'il feat dans la fenetre
*/

int	get_sr(int nb, int x, int i)
{
	if (nb > x)
		return (get_sr(nb / x, x, ++i));
	else
		return (++i);
}

char	*convert(int nb)
{
	char	*base;
	char	*rt;
	int		x;

	rt = malloc(sizeof(char) * (3));
	if (!rt)
		exit(EXIT_FAILURE);
	rt[0] = '0';
	rt[1] = '0';
	base = "0123456789ABCDEF";
	x = 1;
	while (nb > 16 && x >= 0)
	{
		rt[x] = base[nb % 16];
		x--;
		nb = nb / 16;
	}
	rt[x] = base[nb];
	rt[2] = '\0';
	return (rt);
}

char	*convertcol(int nb, int nbx, int nbr)
{
	char	*rtn;
	char	*tmp;

	rtn = "0x";
	tmp = ft_strjoin(rtn, convert(nb));
	rtn = ft_strjoin(tmp, convert(nbx));
	free (tmp);
	tmp = ft_strjoin(rtn, convert(nbr));
	free (rtn);
	return (tmp);
}

t_img	*init_backg(t_cube *cube)
{
	t_img	*backg;

	backg = malloc(sizeof(t_img));
	if (!backg)
		exit (EXIT_FAILURE);
	backg->mlx_img = mlx_new_image(cube->mlx->mlx_ptr, DDWIN_S, DDWIN_S);
	backg->addr = mlx_get_data_addr(backg->mlx_img, &backg->bpp,
			&backg->line_len, &backg->endian);
	backg->pimg = (uint8_t *)backg->addr;
	return (backg);
}
