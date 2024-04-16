/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:38:10 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/16 19:19:56 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include <math.h>
#include <stdio.h>

int		rgbcolor(t_uchr red, t_uchr blue, t_uchr green)
{
	return (red << 16 | blue << 8 | green);
}

void	setpixel(t_mlxdata *app, int x, int y, long color)
{
	long	offset;

	if (x < 0 || y < 0 || x > SIZE_X || y > SIZE_Y)
		return ;
	offset = app->img->size_line * y + x * app->img->bits_per_pixel / 8;
	*(unsigned int *)(offset + app->img->img_pixels) = color;
}

void	isometric(t_mlxdata *app, float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.82);
	*y = (*x + *y) * sin(0.82) - z * app->sc->zscale;
}

void	setvenue(t_crd *crd)
{
	crd->x += crd->xs;
	crd->x_ += crd->xs;
	crd->y += crd->ys;
	crd->y_ += crd->ys;
}

long		ft_max(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}
