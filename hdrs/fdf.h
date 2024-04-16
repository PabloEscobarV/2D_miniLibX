/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:56:21 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/16 14:50:09 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../libft/libft.h"
#include "../get_next_line/get_next_line_bonus.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define HEX_FDF 			"0123456789ABCDEF"
#define SIZE_X 				1900
#define SIZE_Y 				1100
#define MOUSE_SCROLL_UP 	4
#define MOUSE_SCROLL_DOWN 	5
#define ZOOM_IN				65453
#define ZOOM_OUT			65451
#define TITLE				"FdF"

typedef unsigned char	t_uchr;

typedef struct s_dt
{
	float	dx;
	float	dy;
	float	max;
}			t_dt;

typedef struct s_scale
{
	float	scale;
	float	xscale;
	float	yscale;
	float	zscale;
}			t_scale;

typedef struct s_crd
{
	float	x;
	float	y;
	float	z;
	float	x_;
	float	y_;
	float	z_;
	float	xs;
	float	ys;
}			t_crd;

typedef struct s_mapd
{
	int		z;
	long	color;
}			t_mapd;

typedef struct s_map
{
	int		zmax;
	int		zmin;
	size_t	size_x;
	size_t	size_y;
	t_mapd	**crd;
}			t_map;

typedef struct s_color
{
	long	curcolor;
	long	s_color;
	long	f_color;
	float	grad;
}				t_color;

typedef struct s_mlximg
{
	void	*img_ptr;
	char	*img_pixels;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
	int		img_width;
	int		img_height;
}				t_mlximg;

typedef struct s_mlxdata
{
	void		*app;
	void		*wnd;
	t_crd		*crd;
	t_map		*map;
	t_mlximg	*img;
	t_scale		*sc;
	t_color		*color;
}				t_mlxdata;

void		drawmap(t_mlxdata *app);
t_map		*createmap(const char *filename);
////////////////////////////////CRT_APP//////////////////////////////
t_mlxdata	*newmlxdata(void);
t_mlxdata	*crt_mlxdata(t_map *map, t_scale *sc);
void		*ft_free_mlxdata(t_mlxdata	*data);
int			exitapp(void *app);
////////////////////////////////MLX_TOOLS//////////////////////////////
int			rgbcolor(t_uchr red, t_uchr blue, t_uchr green);
void		setpixel(t_mlxdata *app, int x, int y, int color);
void		isometric(t_mlxdata *app, float *x, float *y, float z);
void		setcolor(t_mlxdata *app);
void		setvenue(t_crd *crd);
////////////////////////////////TOOLS//////////////////////////////
void		*free_map(t_map	*crd);
long		tda_size(char ***map);
int			sizematrix(char **mapstr);
long		ft_max(long a, long b);
////////////////////////////////T_MAPD//////////////////////////////
t_mapd		*create_mapd(long z, long color);
t_mapd		*crtmapd(char **mapchar, t_map *map);
// ////////////////////////////////T_CRD//////////////////////////////
t_crd		*crt_crd(float x, float y, float z);
void		scale_crd(t_crd *crd, t_scale *sc);
t_crd		*setcrd_xy(t_crd *crd, int x, int y, t_uchr i);
t_crd		*setxys(t_mlxdata *app, t_crd *crd);
// ////////////////////////////////ROTATION//////////////////////////////
void		rotate(t_crd *crd, int key, float alfa);
void		rotate_x(t_crd *crd, float alfa);
void		rotate_y(t_crd *crd, float alfa);
void		rotate_z(t_crd *crd, float alfa);

void		setzscale(t_mlxdata *app);
t_scale		*crtscale(t_map *map, float zscale, int dx);
void		clear_img(t_mlxdata *app);
int			changevenue(t_mlxdata *app, int key, int i);
int			handleevent(int key, t_mlxdata *app);
int			handle_mouse_scroll(int key, int x, int y, void *app);
// char	*maptostr(char *filename)