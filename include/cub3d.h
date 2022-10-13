/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:58:10 by thbierne          #+#    #+#             */
/*   Updated: 2022/10/13 16:13:44 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stdint.h>
# include <math.h>

//define pour map
# define ccc cube->map->Cellcolor
# define cno cube->map->NO
# define cso cube->map->SO
# define cea cube->map->EA
# define cwe cube->map->WE
# define cfc cube->map->Fcolor
# define cmap cube->map->map

//define pour dimension et nombre carre
# define squax cube->mlx->squarex
# define squay cube->mlx->squarey
# define squat cube->mlx->squaret

//define lier au personnage
# define cpdx cube->mlx->chara->pdx
# define cpdy cube->mlx->chara->pdy
# define chposy cube->mlx->chara->posy
# define chposx cube->mlx->chara->posx
# define cpixelx cube->mlx->chara->pixelx
# define cpixely cube->mlx->chara->pixely

// define de variable
# define ECHAP 65307 // 53 MAC / 65307 Linux
# define W 119
# define D 100
# define A 97
# define S 115
# define pi 3.1415926535
# define winW 1200
# define winH 1200
# define Ppov 60
# define ddwin_s 1200
# define Pov_2 (Ppov / 100) / 2
# define rad_conv (pi / 180)
# define Max_at ((squax / 2) / tan(30 * rad_conv))
# define step (Ppov / 100) / 600

typedef struct	s_cube t_cube;
typedef struct	s_map t_map;
typedef struct	s_mlx t_mlx;
typedef struct	s_img t_img;
typedef struct	s_chara t_chara;
typedef struct	s_ddd t_ddd;
typedef struct	s_ray t_ray;

struct s_ray
{
	float	eucli;
	int		x;
	int		y;
	int		nbr_delta;
	int		side;	// 0 si horizontal / 1 si vertical #le mur bien sur
	float	delta_x; // pour aller d'un bloc a un autre sur l'axe x
	float	delta_y; // pour aller d'un bloc a un autre sur l'axe y
	float	sidedist_x; // dist du joueur a la prochaine cas x
	float	sidedist_y; // dist du joueur a la prochaine cas y
	int		perpwdist; // dist pos joueur pour aller au mur mes en 
//partant du map plane donc pour avoir un axe perpendiculaire   et eviter l'effet fisheye
};

struct s_ddd
{
	void	*win_ptr;
	int		winh;
	int		winw;
	int		index;
	t_img	*ml_img;
};

struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

struct s_map
{
	char	**map;
	char	*NO;
	char	*EA;
	char	*SO;
	char	*WE;
	char	*Fcolor;
	char	*Cellcolor;
};

struct s_chara
{
	t_img	*char_img;
	float	sx;
	float	sy;
	int		pixelx;
	int		pixely;
	int		posx;	//position du joueur par carre dans la map axe x
	int		posy;	//position du joueur par carre dans la map axe Y
	char	dir;	//direction du joueur a la creation
	float	pdx;	//angle de POV axe X
	float	pdy;	//angle de POV axe y
	float	pa;		//angle de POV sous forme pi
};

struct s_mlx
{
	t_img	*img;
	t_chara	*chara;
	int		mapdone;
	int		win_sx;
	int		win_sy;
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	float	squarex;	//nombre de pixel d'un carre axe X
	float	squarey;	//nombre de pixel d'un carre axe y
	int		squaret;	//nombre total de carre de la map
};

struct s_cube
{
	int		largestl;	//taille de la plus longue ligne
	int		nline;		//nombre de ligne de la map
	int		*mapls;		//nombre de carre de la map pour chaque ligne
	int		chara_move;	//0 = le joueur ne bouge pas; 1 = deplacement joueur
	t_mlx	*mlx;
	t_map	*map;
};

/*	check debut de programme	*/

//texture management
int		access_texture(t_map *map);

//error management
void	handle_error(int i);

//check map
int		check_map(t_map *map);
int		print_error_player(int player);

/*	calcul et affichage map	*/

// player related
void	print_chara(t_cube *cube);
t_chara	*init_char(t_cube *cube);
void	img_rotate_character(t_img **img, t_cube *cube, int keysim);
void	print_o_line(t_cube *cube, t_img **line);

// affichage carre
void	get_size_square(t_cube *cube);
void	put_square_on_img(t_cube *cube, int x, int y, int color, t_img **img);

void	img_pix_put(t_img **img, int x, int y, int color, t_cube *cube);

// ray casting
t_ray	*ray_casting(t_cube *cube, float pa);
int		check_ray_y(t_ray *x, t_ray *y, t_cube *cube, float pa);
int		check_y(t_ray *x, t_ray *y, t_cube *cube, float pa);
int		check_ray_y2(t_ray *x, t_ray *y, t_cube *cube, float pa);
int		check_ray_x(t_ray *x, t_ray *y, t_cube *cube, float pa);
int		check_ray_x2(t_ray *x, t_ray *y, t_cube *cube, float pa);
int		check_x_ray(t_ray *x, t_ray *y, t_cube *cube, float pa);

void	init_t_ray(t_ray *x, t_ray *y, t_cube *cube);
void	calcul_sidedist_y(t_ray *y, t_cube *cube, int mode);
void	calcul_delta_y(t_ray *y, t_cube *cube);
void	calcul_sidedist_x(t_ray *x, t_cube *cube, int mode);
void	calcul_delta_x(t_ray *x, t_cube *cube);
t_ray	*return_first_ray(t_ray *x, t_ray *y);

/*	utils	*/

//utils1.c
char	*add_one_char(char *src, int toadd, char c);
char	*remove_rtnl(char *src);
int		get_tab_ylen(char **str, t_cube *cube);
void	tab_xy(t_cube *cube);

//utils2.c
void	print_map(t_cube *cube);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);

/*	image.c	*/

int		handle_keypress(int keysym, t_cube *cube);
void	make_img(t_cube *cube);
void	render_background(t_cube *cube, int color);
int		render(t_cube *cube);
void	ml_loop(t_cube *cube);
void	put_cast_hit(t_cube *cube, int x, int y);

/* struct related */

//init_struct.c
t_mlx	*init_ml(void);
t_cube	*init_cube();
t_map	*init_map();

//free_struct.c
void	free_cube(t_cube *cube);

/* Parsing */

/*	check argument	*/
int		check_cub(char *argv);
int		check_arg(int argc, char **argv);

//parse_cardi.c
int		check_if_right(int fd, char *expected);
int		parse_no(int fd, t_cube *cube);
int		parse_so(int fd, t_cube *cube);
int		parse_ea(int fd, t_cube *cube);
int		parse_we(int fd, t_cube *cube);

//parse_color.c
char	s_wp(int fd);
int		parse_fc(int fd, t_cube *cube);
int		parse_cellcolor(int fd, t_cube *cube);

//skip_error.c
int		manage_error(char c, char *str, int mode);
int		manager(int fd, char c, t_cube *cube, char *str);
int		check_if_set(t_cube *cube);

//map_to_tab.c
int		check_for_wp(char c);
int		read_keep(int fd, char **tab, int x, t_cube *cube);




void	print_ver_line(t_cube *cube);


# endif