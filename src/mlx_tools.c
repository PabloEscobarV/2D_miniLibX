/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:38:10 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/12 22:16:35 by blackrider       ###   ########.fr       */
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
	int	offset;

	offset = app->img->size_line * y + x * app->img->bits_per_pixel / 8;
	*(unsigned int *)(offset + app->img->img_pixels) = color;
}

void	isometric(t_mlxdata *app, float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z * app->sc->k;
}

long	setcolor(t_mlxdata *app, t_crd *crd)
{
	long	color;

	color = app->map->crd[(int)crd->y][(int)crd->x].color;
	if (color)
		return (color);
	if ((app->map->crd[(int)crd->y][(int)crd->x].z
		|| app->map->crd[(int)crd->yf][(int)crd->xf].z))
		color = rgbcolor(50, 255, 50);
	else
		color = rgbcolor(255, 255, 255);
	return (color);
}

void	setvenue(t_mlxdata *app, t_crd *crd)
{
	float	xs;
	float	ys;

	xs = (SIZE_X - app->map->size_x * app->sc->xscale) / (1.3);
	ys = (SIZE_Y - app->map->size_y * app->sc->yscale) / (2.3);
	crd->x += xs;
	crd->xf += xs;
	crd->y += ys;
	crd->yf += ys;
}
