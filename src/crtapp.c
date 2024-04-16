/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crtapp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:34:25 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/16 14:51:08 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>

t_color		*new_color(t_map *map)
{
	t_color	*color;

	if (!map)
		return (NULL);
	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->curcolor = 0;
	color->s_color = rgbcolor(50, 255, 50);
	color->f_color = rgbcolor(255, 10, 50);
	color->grad = (color->f_color - color->s_color) / (map->zmax - map->zmin);
	return (color);
}

t_mlxdata	*newmlxdata(void)
{
	t_mlxdata	*app;

	app = malloc(sizeof(t_mlxdata));
	if (!app)
		return (NULL);
	app->app = NULL;
	app->wnd = NULL;
	app->img = malloc(sizeof(t_mlximg));
	app->map = NULL;
	app->sc = NULL;
	app->crd = crt_crd(0, 0, 0);
	app->color = NULL;
	if (!app->img || !app->crd)
		return (ft_free_mlxdata(app));
	return (app);
}

void		setzscale(t_mlxdata *app)
{
	app->sc->zscale = app->sc->xscale * app->sc->xscale / app->sc->yscale;
	if (fabs(app->sc->zscale * ft_max(abs(app->map->zmax), abs(app->map->zmin)))
		< SIZE_Y / app->sc->scale / 3)
		return ;
	app->sc->zscale = SIZE_Y / (abs(app->map->zmax)  * app->sc->scale * 3);
}

t_mlxdata	*crt_mlxdata(t_map *map, t_scale *sc)
{
	t_mlxdata	*app;

	app = newmlxdata();
	if (!app || !map || !sc)
		return (NULL);
	app->app = mlx_init();
	if (!(app->app))
		return (NULL);
	app->map = map;
	if (!(app->map))
		return (ft_free_mlxdata(app));
	app->wnd = mlx_new_window(app->app, SIZE_X, SIZE_Y, TITLE);
	if (!(app->wnd))
		return (ft_free_mlxdata(app));
	app->img->img_ptr = mlx_new_image(app->app, SIZE_X, SIZE_Y);
	app->img->img_pixels = mlx_get_data_addr(app->img->img_ptr,
			&app->img->bits_per_pixel, &app->img->size_line,
			&app->img->endian);
	if (!(app->img->img_ptr) || !(app->img->img_pixels))
		return (ft_free_mlxdata(app));
	app->sc = sc;
	app->color = new_color(map);
	setxys(app, app->crd);
	setzscale(app);
	return (app);
}

t_mapd	*create_mapd(long z, long color)
{
	t_mapd	*tmp;

	tmp = malloc(sizeof(t_mapd));
	if (!tmp)
		return (NULL);
	tmp->z = z;
	tmp->color = color;
	return (tmp);
}
