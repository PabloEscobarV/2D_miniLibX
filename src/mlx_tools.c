/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:38:10 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/12 10:40:44 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

int		rgbcolor(t_uchr red, t_uchr blue, t_uchr green)
{
	return (red << 16 | blue << 8 | green);
}

void	setpixel(t_mlxdata *app, int x, int y, int color)
{
	int	offset;

	offset = app->img->size_line * y + x * app->img->bits_per_pixel / 8;
	*(unsigned int *)(offset + app->img->img_pixels) = color;
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = ((*x + *y) * sin(0.8) - z * 2);
}

long	setcolor(t_mlxdata *app, int x, int y, int xf, int yf)
{
	long	color;

	color = app->map->crd[y][x].color;
	if (color)
		return (color);
	if ((app->map->crd[y][x].z || app->map->crd[yf][xf].z))
		color = rgbcolor(50, 255, 50);
	else
		color = rgbcolor(255, 255, 255);
	return (color);
}

void	setvenue(t_mlxdata *app, float *x, float *y, float *xf, float *yf)
{
	float	xs;
	float	ys;

	xs = (SIZE_X - app->map->size_x * app->sc->xscale) / (1.3);
	ys = (SIZE_Y - app->map->size_y * app->sc->yscale) / (2.3);
	*x += xs;
	*xf += xs;
	*y += ys;
	*yf += ys;
}
