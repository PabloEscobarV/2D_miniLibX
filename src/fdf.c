/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:09:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/11 14:13:57 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

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
	return (data);
}

t_mlxdata	*crt_mlxdata(const char *filename, int scale)
{
	t_mlxdata	*data;

	data = newmlxdata();
	if (!data)
		return (NULL);
	data->app = mlx_init();
	if (!(data->app))
		return (NULL);
	data->map = createmap(filename);
	if (!(data->map))
		return (ft_free_mlxdata(data));
	data->wnd = mlx_new_window(data->app, MIN(SIZE_X, data->map->size_x * 3 *
		scale), MIN(SIZE_Y, data->map->size_y * 3 * scale), TITLE);
	data->img = malloc(sizeof(t_mlximg));
	if (!(data->wnd) || !(data->img))
		return (ft_free_mlxdata(data));
	data->img->img_ptr = mlx_new_image(data->app, data->map->size_x * scale,
		data->map->size_y * scale);
	data->img->img_pixels = mlx_get_data_addr(data->img->img_ptr,
		&data->img->bits_per_pixel, &data->img->size_line, &data->img->endian);
	if (!(data->img->img_ptr) || !(data->img->img_pixels))
		return (ft_free_mlxdata(data));
	data->scale = scale;
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

// 	dx = crd->x_f - crd->x;
// 	dy = crd->y_f - crd->y;
// 	max = MAX(MOD(dx), MOD(dy));
// 	dx /= max;
// 	dy /= max;
// 	while ((int)(crd->x_f - crd->x) || (int)(crd->y_f - crd->y))
// 	{
// 		setpixel(app, crd->x, crd->y, rgbcolor(255, 0, 0));
// 		// mlx_pixel_put(app->app, app->wnd, crd->x, crd->y, rgbcolor(255, 0, 0));
// 		crd->x += dx;
// 		crd->y += dy;
// 	}
// 	// mlx_clear_window(app->app, app->wnd);
// 	// mlx_put_image_to_window(app->app, app->wnd, app->img->img_ptr, 0, 0);
// }

void	brensenhem(t_mlxdata *app, float x, float y, int x_f, int y_f)
{
	int				color;
	float			dx;
	float			dy;
	float			max;

	if (app->map->crd[(int)y][(int)x].z)
		color = rgbcolor(255, 0, 0);
	else
		color = rgbcolor(0, 0, 0);
	x *= app->scale;
	y *= app->scale;
	x_f *= app->scale;
	y_f *= app->scale;
	dx = x_f - x;
	dy = y_f - y;
	max = MAX(MOD(dx), MOD(dy));
	dx /= max;
	dy /= max;
	while ((int)(x_f - x) || (int)(y_f - y))
	{
		setpixel(app, x, y, color);
		x += dx;
		y += dy;
	}
}

t_crd	*crt_crd(int x, int y, int x_f, int y_f)
{
	t_crd	*tmp;

	tmp = malloc(sizeof(t_crd));
	if (!tmp)
		return (NULL);
	tmp->x = (float)x;
	tmp->y = (float)y;
	tmp->x_f = x_f;
	tmp->y_f = y_f;
	return (tmp);
}

t_crd	*scale_crd(t_crd *crd, int scale)
{
	if (!crd)
		return (NULL);
	crd->x *= (float)scale;
	crd->y *= (float)scale;
	crd->x_f *= scale;
	crd->y_f *= scale;
	return (crd);
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

int	main(void)
{
	int			scale;
	t_mlxdata	*app;
	t_crd		*crd;

	scale = 20;
	app = crt_mlxdata("../maps/test_maps/42.fdf", scale * 2);
	crd = scale_crd(crt_crd(0, 10, 10, 10), scale);
	// brensenhem(app, crd);
	drawmap(app);
	mlx_hook(app->wnd, 17, 1L<<3, exitapp, app);
	mlx_loop(app->app);
	return (0);
}
