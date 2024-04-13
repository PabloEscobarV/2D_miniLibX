/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:09:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/13 13:37:26 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <math.h>

void	brensenhem(t_mlxdata *app, t_crd *crd)
{
	long			color;
	int				z;
	int				z1;
	t_dt			dt;

	z = app->map->crd[(int)(crd->y)][(int)(crd->x)].z;
	z1 = app->map->crd[(int)(crd->yf)][(int)(crd->xf)].z;
	color = setcolor(app, crd);
	scale_crd(crd, app->sc);
	isometric(app, &crd->x, &crd->y, z);
	isometric(app, &crd->xf, &crd->yf, z1);
	setvenue(crd);
	dt.dx = crd->xf - crd->x;
	dt.dy = crd->yf - crd->y;
	dt.max = fmax(fabs(dt.dx), fabs(dt.dy));
	dt.dx /= dt.max;
	dt.dy /= dt.max;
	while ((int)(crd->xf - crd->x) || (int)(crd->yf - crd->y))
	{
		setpixel(app, crd->x, crd->y, color);
		crd->x += dt.dx;
		crd->y += dt.dy;
	}
}

void	drawmap(t_mlxdata *app)
{
	int		x;
	int		y;
	t_crd	crd;

	if (!app)
		return ;
	setxys(app, &crd);
	y = 0;
	while (y < (int)app->map->size_y)
	{
		x = 0;
		while (x < (int)app->map->size_x)
		{
			if (x < (int)app->map->size_x - 1)
				brensenhem(app, setcrd_xy(&crd, x, y, 0));
			if (y < (int)app->map->size_y - 1)
				brensenhem(app, setcrd_xy(&crd, x, y, 1));
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
	drawmap(app);
	mlx_hook(app->wnd, 17, 1L << 3, exitapp, app);
	mlx_loop(app->app);
	return (0);
}

	// if (argc == 2)
	// 	map = createmap(argv[1]);
	// else
	// 	map = createmap("../maps/mars.fdf");