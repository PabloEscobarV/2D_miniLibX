/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:09:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/12 10:21:42 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <math.h>

void		*ft_free_mlxdata(t_mlxdata	*data)
{
	if (data->img)
		mlx_destroy_image(data->app, data->img->img_ptr);
	if (data->wnd)
		mlx_destroy_window(data->app, data->wnd);
	if (data->app)
		mlx_destroy_display(data->app);
	free_map(data->map);
	free(data->img);
	free(data->app);
	free(data);
	return (NULL);
}

t_mlxdata	*newmlxdata()
{
	t_mlxdata	*data;

	data = malloc(sizeof(t_mlxdata));
	if (!data)
		return (NULL);
	data->app = NULL;
	data->wnd = NULL;
	data->img = NULL;
	data->map = NULL;
	data->sc = NULL;
	return (data);
}

t_mlxdata	*crt_mlxdata(t_map *map, t_scale *sc)
{
	t_mlxdata	*data;

	data = newmlxdata();
	if (!data)
		return (NULL);
	data->app = mlx_init();
	if (!(data->app))
		return (NULL);
	data->map = map;
	if (!(data->map))
		return (ft_free_mlxdata(data));
	data->wnd = mlx_new_window(data->app, SIZE_X, SIZE_Y, TITLE);
	data->img = malloc(sizeof(t_mlximg));
	if (!(data->wnd) || !(data->img))
		return (ft_free_mlxdata(data));
	data->img->img_ptr = mlx_new_image(data->app, SIZE_X, SIZE_Y);
	data->img->img_pixels = mlx_get_data_addr(data->img->img_ptr,
		&data->img->bits_per_pixel, &data->img->size_line, &data->img->endian);
	if (!(data->img->img_ptr) || !(data->img->img_pixels))
		return (ft_free_mlxdata(data));
	data->sc = sc;
	return (data);
}

int		exitapp(void *app)
{
	ft_free_mlxdata((t_mlxdata *)app);
	exit(0);
	return (0);
}

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

// void	brensenhem(t_mlxdata *app, t_crd *crd)
// {
// 	float	dx;
// 	float	dy;
// 	float	max;

// 	dx = crd->xf - crd->x;
// 	dy = crd->yf - crd->y;
// 	max = MAX(MOD(dx), MOD(dy));
// 	dx /= max;
// 	dy /= max;
// 	while ((int)(crd->xf - crd->x) || (int)(crd->yf - crd->y))
// 	{
// 		setpixel(app, crd->x, crd->y, rgbcolor(255, 0, 0));
// 		// mlx_pixel_put(app->app, app->wnd, crd->x, crd->y, rgbcolor(255, 0, 0));
// 		crd->x += dx;
// 		crd->y += dy;
// 	}
// 	// mlx_clear_window(app->app, app->wnd);
// 	// mlx_put_image_to_window(app->app, app->wnd, app->img->img_ptr, 0, 0);
// }

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = ((*x + *y) * sin(0.8) - z * 2);
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
	// *x += app->sc->xscale * app->map->size_x / (app->map->size_x / app->map->size_y);
	// *y += app->sc->yscale * app->map->size_y / 15;
	// *xf += app->sc->xscale * app->map->size_x / (app->map->size_x / app->map->size_y);
	// *yf += app->sc->yscale * app->map->size_y / 15;
	// *x += 150;
	// *y += 150;
	// *xf += 150;
	// *yf += 150;
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

t_crd	*crt_crd(int x, int y, int xf, int yf)
{
	t_crd	*tmp;

	tmp = malloc(sizeof(t_crd));
	if (!tmp)
		return (NULL);
	tmp->x = (float)x;
	tmp->y = (float)y;
	tmp->xf = xf;
	tmp->yf = yf;
	return (tmp);
}

t_crd	*scale_crd(t_crd *crd, int scale)
{
	if (!crd)
		return (NULL);
	crd->x *= (float)scale;
	crd->y *= (float)scale;
	crd->xf *= scale;
	crd->yf *= scale;
	return (crd);
}

void	drawmap(t_mlxdata *app)
{
	int		x;
	int		y;

	if (!app)
		return ;
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
			// mlx_clear_window(app->app, app->wnd);
			// mlx_put_image_to_window(app->app, app->wnd, app->img->img_ptr, 0, 0);
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
