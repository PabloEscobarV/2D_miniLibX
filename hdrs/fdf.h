/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:56:21 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/11 20:49:23 by blackrider       ###   ########.fr       */
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
	int		xf;
	int		yf;
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

// typedef	struct s_map
// {
// 	int		x;
// 	int		y;
// 	int		z;
// 	long	color;
// }			t_map;

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

// typedef struct s_mlxdata
// {
// 	void		*app;
// 	void		*mlxwindow;
// 	t_mlximg	*img;
// 	t_mlximg	*wall;
// 	t_mlximg	*pacman;
// 	t_mlximg	*enemy;
// }				t_mlxdata;

t_map	*createmap(const char *filename);
////////////////////////////////TOOLS//////////////////////////////
void	*free_map(t_map	*crd);
long	tda_size(char ***map);
int		sizematrix(char **mapstr);
////////////////////////////////T_MAPD//////////////////////////////
t_mapd  *create_mapd(long z, long color);
// ////////////////////////////////MAPTTOSTR//////////////////////////////
// char	*maptostr(char *filename);