/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:09:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/15 11:30:48 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

void	brensenhem(t_mlxdata *app, t_crd *crd)
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

void	printdata(t_mlxdata *app, int count, ...)
{
	int	i;
	va_list	arg;

	va_start(arg, count);
	i = 0;
	while (i < count)
	{
		mlx_string_put(app->app, app->wnd, 10, 10 + 10 * i, rgbcolor(255, 255, 255),
			va_arg(arg, char *));
		++i;
	}
	va_end(arg);
}

void	drawmap(t_mlxdata *app)
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
				brensenhem(app, setcrd_xy(app->crd, x, y, 0));
			if (y < (int)app->map->size_y - 1)
				brensenhem(app, setcrd_xy(app->crd, x, y, 1));
			++x;
		}
		++y;
	}
	mlx_clear_window(app->app, app->wnd);
	mlx_put_image_to_window(app->app, app->wnd, app->img->img_ptr, 0, 0);
	printdata(app, 2, "For zoom press '+' or '-'", "For move pres arrows");
}

int	main(int argc, char **argv)
{
	int			scale;
	int			dx;
	t_map		*map;
	t_mlxdata	*app;

	dx = 3;
	scale = 1;
	if (argc < 2)
		exit(-1);
	if (argc > 3 && ft_atoi(argv[3]))
		dx = ft_atoi(argv[3]);
	if (argc > 2 && ft_atoi(argv[2]))
		scale = ft_atoi(argv[2]);
	map = createmap(argv[1]);
	if (!map)
		exit(-1);
	app = crt_mlxdata(map, crtscale(map, scale, dx));
	drawmap(app);
	mlx_hook(app->wnd, 4, 0, handle_mouse_scroll, app);
	mlx_hook(app->wnd, 2, 1L, handleevent, app);
	mlx_hook(app->wnd, 17, 1L << 3, exitapp, app);
	mlx_loop(app->app);
	return (0);
}
