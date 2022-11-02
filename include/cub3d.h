/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:58:10 by thbierne          #+#    #+#             */
/*   Updated: 2022/11/02 14:54:02 by avillar          ###   ########.fr       */
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

// define de variable
# define ECHAP 65307
# define W 119
# define D 100
# define A 97
# define S 115
# define PI 3.1415926535
# define WINW 1200
# define WINH 1200
# define PPOV 60
# define CSX 400
# define DF 65363
# define GF 65361
# define DDWIN_S 1200

typedef struct s_cube	t_cube;
typedef struct s_map	t_map;
typedef struct s_mlx	t_mlx;
typedef struct s_img	t_img;
typedef struct s_chara	t_chara;
typedef struct s_ddd	t_ddd;
typedef struct s_ray	t_ray;
typedef struct s_axpm	t_axpm;
typedef struct s_tdata	t_tdata;
typedef struct s_key	t_key;

//pos_rayx[2]; coordonner impact rayon x (x,y)
//pos_rayy[2]; coordonner impact rayon y (x,y)

//nbr_delta[2];	 nombre de distance delta parcouru (0 pour x, 1 pour y)
//side; 0 si horizontal / 1 si vertical #le mur bien sur
//delta[2]; distance delta parcouru (0 pour x, 1 pour y)
//sidedist[2]; distance sidedist parcouru (0 pour x, 1 pour y)

//dist_x; distance d'un cube axe x
//dist_y; distance d'un cube axe y
//x; distance du joueur jusqu'au mur axe x
//y; distance du joueur jusqu'au mur axe y
//a; valeur pour savoir dans quel carre est le joueur axe x

//c; valeur pour savoir dans quel carre est le joueur axe y

struct	s_ray
{
	double		eucli;
	int			pos_rayx[2];
	int			pos_rayy[2];
	double		pdx;
	double		pdy;
	int			nbr_delta[2];	
	int			side;
	double		delta[2];
	double		sidedist[2];
	double		perpwdist;
	double		dist_x;
	double		dist_y;
	double		x;
	double		y;
	int			a;
	int			b;
	int			c;
	int			d;
};

struct	s_ddd
{
	void		*win_ptr;
	int			winh;
	int			winw;
	int			index;
	t_img		*backg;
};

struct	s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	uint8_t		*pimg;
};

struct	s_map
{
	int			error;
	char		**map;
	char		*no;
	char		*ea;
	char		*so;
	char		*we;
	char		**fcolor;
	char		**cellcolor;
};

//posx; position du joueur par carre dans la map axe x
//posy; position du joueur par carre dans la map axe Y
//dir; direction du joueur a la creation
//pdx; angle de POV axe X
//pdy; angle de POV axe y
//pa; angle de POV sous forme pi

struct	s_chara
{
	float		sx;
	float		sy;
	int			pixelx;
	int			pixely;
	float		p_per[2];
	int			posx;
	int			posy;
	char		dir;
	float		pdx;
	float		pdy;
	float		pa;
};

//squarex; nombre de pixel d'un carre axe X
//squarey; nombre de pixel d'un carre axe y
//squaret; nombre total de carre de la map

struct	s_mlx
{
	t_img		*img;
	t_chara		*chara;
	int			mapdone;
	int			win_sx;
	int			win_sy;
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
	float		squarex;
	float		squarey;
	int			squaret;
};

struct	s_axpm
{
	t_tdata		*no;
	t_tdata		*so;
	t_tdata		*we;
	t_tdata		*ea;
};
struct s_tdata
{
	t_img		*img;
	int			size_x;
	int			size_y;
	int			index_b;
	int			index_t;
};

//largestl	taille de la plus longue ligne
//nline		nombre de ligne de la map
//mapls		nombre de carre de la map pour chaque ligne
//chara_move   0 = le joueur ne bouge pas; 1 = deplacement joueur

struct s_key
{
	int			move;
	int			turn;
	int			np;
	int			sp;
	int			wp;
	int			ep;
	int			df;
	int			gf;
};

struct s_cube
{
	int			largestl;
	int			nline;
	int			*mapls;
	int			chara_move;
	t_axpm		*texture;
	t_mlx		*mlx;
	t_map		*map;
	t_ddd		*dd;
	t_key		*key;
};

/*	check debut de programme	*/

//texture management
int		access_texture(t_map *map);

//error management
int		handle_error(int i);

//check map
int		check_map(t_map *map);
int		print_error_player(int player);
int		look_around(char **map, int i, int y);

/*	calcul et affichage map	*/

// player related
void	print_chara(t_cube *cube);
t_chara	*init_char(t_cube *cube);
void	img_rotate_character(t_cube *cube, int keysim);
void	print_o_line(t_cube *cube, t_img **line);

void	player_up(t_cube *cube);
void	player_down(t_cube *cube);
void	player_rotate_left(t_cube *cube);
void	player_rotate_right(t_cube *cube);

// affichage carre
void	get_size_square(t_cube *cube);

// ray casting
t_ray	*ray_casting(t_cube *cube, float pa);
void	detect_wall(t_ray *ray, t_cube *cube);
void	change_ray_y(t_cube *cube, t_ray *ray, double *dist_y);
void	change_ray_x(t_cube *cube, t_ray *ray, double *dist_x);
void	check_ray_middle(t_cube *cube, t_ray *ray);
void	setup_ray(t_cube *cube, t_ray *ray);
void	modif_x_y(t_ray *ray);

void	init_t_ray(t_ray *ray, float pa, t_cube *cube);
void	return_side(t_ray *ray);
void	calcul_plan_chara(t_cube *cube);
void	check_ray(t_ray *ray, t_cube *cube);
void	check_wall_y(t_ray *ray, t_cube *cube, int x, int y);
void	check_wall_x(t_ray *ray, t_cube *cube, int x, int y);
void	calcul_eucli(t_ray *ray, t_cube *cube, int i);
void	alloc_sidedist(t_ray *ray, t_cube *cube, int i);
void	alloc_delta(t_ray *ray, t_cube *cube, int i);

/*	utils	*/

//utils1.c
char	*add_one_char(char *src, char c);
char	*remove_rtnl(char *src);
int		get_tab_ylen(char **str, t_cube *cube);
void	tab_xy(t_cube *cube);

//utils2.c
void	print_map(t_cube *cube);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	free_split(char **split);

/*	image.c	*/

int		handle_keypress(int keysym, t_cube *cube);
int		render(t_cube *cube);
void	ml_loop(t_cube *cube);

/* struct related */

//init_struct.c
t_mlx	*init_ml(void);
t_cube	*init_cube(void);
t_map	*init_map(void);

//free_struct.c
void	dest_mlx(t_cube *cube);
void	free_map_map(char **map);
void	free_splits(t_cube *cube);
void	free_cube(t_cube *cube);
void	free_split(char **split);

/* Parsing */

/*	check argument	*/
int		check_cub(char *argv);
int		check_arg(int argc, char **argv);

//parse_cardi.c
int		check_double(t_cube *cube, int n);
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
int		manage_error(char c, int mode, t_cube *cube);
int		manager(int fd, char c, t_cube *cube);
int		check_if_set(t_cube *cube);

//map_to_tab.c
int		check_for_wp(char c);
int		read_keep(int fd, t_cube *cube);
int		check_for_wp(char c);
char	*reset_rtn(char *rtn);
char	*skip(int fd);
char	*map_to_str(int fd);
void	print_ver_line(t_cube *cube);

//test 3d

void	color_pixel(uint8_t *pixel, uint8_t *color);
void	draw_north(t_ddd **dd, t_cube *cube, t_ray *ray);
uint8_t	*get_colors(char *s1, char *s2, char *s3);
void	draw_east(t_ddd **dd, t_cube *cube, t_ray *ray);
void	draw_west(t_ddd **dd, t_cube *cube, t_ray *ray);
void	draw_south(t_ddd **dd, t_cube *cube, t_ray *ray);

//test 3d

char	**malloc_lines(char **dest, int l, int n);
char	**put_space(char **map, int l, int n);
int		get_n_line(char **map);
int		get_largest_l(char **map);
int		check_if_here(t_cube *cube);
t_ddd	*init_ddd(t_cube *cube);

//test texture
void	free_textures(t_cube *cube, t_axpm *texture);
t_axpm	*init_texture(t_cube *cube);
uint8_t	*get_tex_color_bot(t_cube *cube, t_tdata *data, float h, int x);
uint8_t	*get_tex_color_top(t_cube *cube, t_tdata *data, float h, int x);
void	reset_index(t_cube *cube);

//calcul_3d
int		get_sr(int nb, int x, int i);
char	*convert(int nb);
char	*convertcol(int nb, int nbx, int nbr);
t_img	*init_backg(t_cube *cube);
t_ddd	*init_ddd(t_cube *cube);

//utils_3d.c
void	color_pixel(uint8_t *pixel, uint8_t *color);
void	draw_back(t_img **backg, uint8_t *ceil, uint8_t *floor);

#endif