/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:56:21 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/01 21:44:05 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef unsigned char uchar;

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
	t_mlximg	*wall;
	t_mlximg	*pacman;
	t_mlximg	*enemy;
}				t_mlxdata;