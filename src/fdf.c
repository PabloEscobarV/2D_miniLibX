/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:09:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/14 20:26:53 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdio.h>
#include <math.h>

void	brensenhem(t_mlxdata *app, t_crd *crd, int key, float alfa)
{
	long			color;
	t_dt			dt;

	crd->z = app->map->crd[(int)(crd->y)][(int)(crd->x)].z;
	crd->z_ = app->map->crd[(int)(crd->y_)][(int)(crd->x_)].z;
	color = setcolor(app, crd);
	scale_crd(crd, app->sc);
	isometric(app, &crd->x, &crd->y, crd->z);
	isometric(app, &crd->x_, &crd->y_, crd->z_);
	setvenue(crd);
	rotate(crd, key, alfa);
	dt.dx = crd->x_ - crd->x;
	dt.dy = crd->y_ - crd->y;
	dt.max = fmax(fabs(dt.dx), fabs(dt.dy));
	dt.dx /= dt.max;
	dt.dy /= dt.max;
	while ((int)(crd->x_ - crd->x) || (int)(crd->y_ - crd->y))
	{
		setpixel(app, crd->x, crd->y, color);
		crd->x += dt.dx;
		crd->y += dt.dy;
	}
}

void	drawmap(t_mlxdata *app, int key, float alfa)
{
	int		x;
	int		y;

	if (!app)
		return ;
	y = 0;
	while (y < (int)app->map->size_y)
	{
		x = 0;
		while (x < (int)app->map->size_x)
		{
			if (x < (int)app->map->size_x - 1)
				brensenhem(app, setcrd_xy(app->crd, x, y, 0), key, alfa);
			if (y < (int)app->map->size_y - 1)
				brensenhem(app, setcrd_xy(app->crd, x, y, 1), key, alfa);
			++x;
		}
		++y;
	}
	mlx_clear_window(app->app, app->wnd);
	mlx_put_image_to_window(app->app, app->wnd, app->img->img_ptr, 0, 0);
}

int	findmax(t_map *map)
{
	int	i;
	int	j;
	int	max;

	max = 0;
	i = 0;
	while (i < (int)map->size_y)
	{
		j = 0;
		while (j < (int)map->size_x)
		{
			if (abs((int)map->crd[i][j].z) > abs(max))
				max = map->crd[i][j].z;
			++j;
		}
		++i;
	}
	return (max);
}

t_scale	*crtscale(t_map *map, float zscale, int dx)
{
	t_scale	*scale;

	if (dx < 0)
		dx = 2;
	if (zscale < 0)
		zscale = 1.0;
	scale = malloc(sizeof(t_scale));
	if (!map || !scale)
		return (NULL);
	scale->scale = (float)dx;
	scale->xscale = (float)SIZE_X / dx / (float)map->size_x;
	scale->yscale = (float)SIZE_Y / dx / (float)map->size_y;
	scale->zscale = zscale;
	printf("scale: %f\tzscale: %f\n", scale->scale, scale->zscale);
	return (scale);
}

void	clear_img(t_mlxdata *app)
{
	mlx_destroy_image(app->app, app->img->img_ptr);
	app->img->img_ptr = mlx_new_image(app->app, SIZE_X, SIZE_Y);
	app->img->img_pixels = mlx_get_data_addr(app->img->img_ptr,
			&app->img->bits_per_pixel, &app->img->size_line,
			&app->img->endian);
}

int		changevenue(t_mlxdata *app, int key, int i)
{
	if (key != XK_Up && key != XK_Down && key != XK_Left && key != XK_Right)
		return (0);
	if (key == XK_Up)
		app->crd->ys -= i;
	if (key == XK_Down)
		app->crd->ys += i;
	if (key == XK_Left)
		app->crd->xs -= i;
	if (key == XK_Right)
		app->crd->xs += i;
	clear_img(app);
	drawmap(app, 0, 0);
	return (1);
}

int		handlerotate(t_mlxdata *app, int key)
{
	if (key != XK_w && key != XK_s && key != XK_a && key != XK_d)
		return (0);
	clear_img(app);
	drawmap(app, key, 0.1);
	return (0);
}

int		handleevent(int key, t_mlxdata *app)
{
	if (key == XK_Escape)
		exitapp(app);
	if (changevenue(app, key, 10))
		return (0);
	return (handlerotate(app, key));
}

int	main(int argc, char **argv)
{
	int			scale;
	int			dx;
	t_map		*map;
	t_mlxdata	*app;

	dx = 2;
	scale = 1;
	if (argc < 2)
		exit(-1);
	if (argc > 3)
		dx = ft_atoi(argv[3]);
	if (argc > 2)
		scale = ft_atoi(argv[2]);
	map = createmap(argv[1]);
	if (!map)
		exit(-1);
	app = crt_mlxdata(map, crtscale(map, scale, dx));
	drawmap(app, 0, 0);
	mlx_hook(app->wnd, 2, 1L, handleevent, app);
	mlx_hook(app->wnd, 17, 1L << 3, exitapp, app);
	mlx_loop(app->app);
	return (0);
}
	// if (argc == 2)
	// 	map = createmap(argv[1]);
	// else
	// 	map = createmap("../maps/mars.fdf");