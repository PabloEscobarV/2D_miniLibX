/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:09:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/12 10:39:13 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <math.h>

void	brensenhem(t_mlxdata *app, float x, float y, float xf, float yf)
{
	long			color;
	float			dx;
	float			dy;
	float			max;
	int				z;
	int				z_f;

	z = app->map->crd[(int)y][(int)x].z;
	z_f = app->map->crd[(int)yf][(int)xf].z;
	color = setcolor(app, x, y, xf, yf);
	x *= app->sc->xscale;
	y *= app->sc->yscale;
	xf *= app->sc->xscale;
	yf *= app->sc->yscale;
	isometric(&x, &y, z);
	isometric(&xf, &yf, z_f);
	setvenue(app, &x, &y, &xf, &yf);
	dx = xf - x;
	dy = yf - y;
	max = MAX(MOD(dx), MOD(dy));
	dx /= max;
	dy /= max;
	while ((int)(xf - x) || (int)(yf - y))
	{
		setpixel(app, x, y, color);
		x += dx;
		y += dy;
	}
}

void	drawmap(t_mlxdata *app)
{
	int		x;
	int		y;
	t_crd	*crd;

	if (!app)
		return ;
	crd = crt_crd(0, 0, 0, 0);
	y = 0;
	while (y < app->map->size_y)
	{
		x = 0;
		while (x < app->map->size_x)
		{
			if (x < app->map->size_x - 1)
				brensenhem(app, x, y, x + 1, y);
			if (y < app->map->size_y - 1)
				brensenhem(app, x, y, x, y + 1);
			++x;
		}
		++y;
	}
	mlx_clear_window(app->app, app->wnd);
	mlx_put_image_to_window(app->app, app->wnd, app->img->img_ptr, 0, 0);
}

t_scale	*crtscale(t_map *map, int size_x, int size_y, float k)
{
	t_scale *scale;

	scale = malloc(sizeof(t_scale));
	scale->xscale = 1 * ((float)size_x / k) / (float)(map->size_x);
	scale->yscale = 1 * (((float)size_y / k) / (float)(map->size_y));
	return (scale);
}

int	main(void)
{
	int			alfa;
	t_scale		*scale;
	t_map		*map;
	t_mlxdata	*app;

	map = createmap("../maps/test_maps/42.fdf");
	scale = crtscale(map, SIZE_X, SIZE_Y, 2);
	app = crt_mlxdata(map, scale);
	drawmap(app);
	mlx_hook(app->wnd, 17, 1L<<3, exitapp, app);
	mlx_loop(app->app);
	return (0);
}
