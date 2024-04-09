/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:56:21 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/09 13:23:28 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../get_next_line/get_next_line_bonus.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define	HEX_FDF "0123456789ABCDEF"
#define SIZE_X 800
#define SIZE_Y 800

typedef unsigned char t_uchr;

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
}			t_crd;

typedef	struct s_map
{
	int		x;
	int		y;
	int		z;
	long	color;
}			t_map;

typedef	struct s_mlximg
{
	void	*img_ptr;
	char	*img_pixels;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
}				t_mlximg;

typedef struct s_mlxdata
{
	void		*mlxapp;
	void		*mlxwindow;
	t_mlximg	*img;
	t_mlximg	*wall;
	t_mlximg	*pacman;
	t_mlximg	*enemy;
}				t_mlxdata;

////////////////////////////////TOOLS//////////////////////////////
void	*freedub(void **ptr);
void	*freetriple(void ***ptr);
////////////////////////////////MAPTTOSTR//////////////////////////////
char	***maptostr(char *filename);