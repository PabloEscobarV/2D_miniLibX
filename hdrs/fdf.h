/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:56:21 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/12 10:40:45 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../get_next_line/get_next_line_bonus.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define	HEX_FDF 	"0123456789ABCDEF"
#define SIZE_X 		1850
#define SIZE_Y 		850
#define	TITLE		"FdF"
#define	MAX(a, b)	(a > b ? a : b)
#define	MIN(a, b)	(a < b ? a : b)
#define MOD(a) 		((a < 0) ? -a : a)

typedef unsigned char t_uchr;

typedef struct
{
	float	xscale;
	float	yscale;
}			t_scale;

typedef struct 
{
	float	x;
	float	y;
	float	xf;
	float	yf;
}			t_crd;

typedef struct
{
	long	z;
	long	color;
}			t_mapd;

typedef struct
{
	size_t	size_x;
	size_t	size_y;
	t_mapd	**crd;
}			t_map;

typedef	struct s_mlximg
{
	void	*img_ptr;
	char	*img_pixels;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
	int		img_width;
	int		img_height;
}				t_mlximg;

typedef struct	s_mlxdata
{
	void		*app;
	void		*wnd;
	t_mlximg	*img;
	t_map		*map;
	t_scale		*sc;
}				t_mlxdata;


t_map	*createmap(const char *filename);
////////////////////////////////CRT_APP//////////////////////////////
t_mlxdata	*newmlxdata();
t_mlxdata	*crt_mlxdata(t_map *map, t_scale *sc);
void		*ft_free_mlxdata(t_mlxdata	*data);
int			exitapp(void *app);
////////////////////////////////MLX_TOOLS//////////////////////////////
int			rgbcolor(t_uchr red, t_uchr blue, t_uchr green);
void		setpixel(t_mlxdata *app, int x, int y, int color);
void		isometric(float *x, float *y, int z);
long		setcolor(t_mlxdata *app, int x, int y, int xf, int yf);
void		setvenue(t_mlxdata *app, float *x, float *y, float *xf, float *yf);
////////////////////////////////TOOLS//////////////////////////////
void		*free_map(t_map	*crd);
long		tda_size(char ***map);
int			sizematrix(char **mapstr);
////////////////////////////////T_MAPD//////////////////////////////
t_mapd  	*create_mapd(long z, long color);
// ////////////////////////////////T_CRD//////////////////////////////
t_crd		*crt_crd(int x, int y, int xf, int yf);
void    	scale_crd(t_crd *crd, int scale);
void		setcrd_xy(t_crd *crd, int x, int y, t_uchr i);
// char	*maptostr(char *filename);