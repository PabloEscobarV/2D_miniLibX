/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:38:10 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/15 14:30:05 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include <math.h>
#include <stdio.h>

int	rgbcolor(t_uchr red, t_uchr blue, t_uchr green)
{
	return (red << 16 | blue << 8 | green);
}

void	setpixel(t_mlxdata *app, int x, int y, int color)
{
	long	offset;

	if (x < 0 || y < 0 || x > SIZE_X || y > SIZE_Y)
		return ;
	offset = app->img->size_line * y + x * app->img->bits_per_pixel / 8;
	*(unsigned int *)(offset + app->img->img_pixels) = color;
}

void	isometric(t_mlxdata *app, float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z * app->sc->zscale;
}

long	setcolor(t_mlxdata *app, t_crd *crd)
{
	long	color;

	color = app->map->crd[(int)crd->y][(int)crd->x].color;
	if (color)
		return (color);
	if ((app->map->crd[(int)crd->y][(int)crd->x].z
		|| app->map->crd[(int)crd->y_][(int)crd->x_].z))
		color = rgbcolor(50, 255, 50);
	else
		color = rgbcolor(255, 255, 255);
	return (color);
}

void	setvenue(t_crd *crd)
{
	crd->x += crd->xs;
	crd->x_ += crd->xs;
	crd->y += crd->ys;
	crd->y_ += crd->ys;
}
