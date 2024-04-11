/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:09:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/11 12:38:51 by blackrider       ###   ########.fr       */
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
	data->wnd = mlx_new_window(data->app, MAX(SIZE_X, data->map->size_x * 3 *
		scale), MAX(SIZE_Y, data->map->size_y * 3 * scale), TITLE);
	data->img = malloc(sizeof(t_mlximg));
	if (!(data->wnd) || !(data->img))
		return (ft_free_mlxdata(data));
	data->img->img_ptr = mlx_new_image(data->app, data->map->size_x * scale,
		data->map->size_y * scale);
	data->img->img_pixels = mlx_get_data_addr(data->img->img_ptr,
		&data->img->bits_per_pixel, &data->img->size_line, &data->img->endian);
	if (!(data->img->img_ptr) || !(data->img->img_pixels))
		return (ft_free_mlxdata(data));
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

int		brensenhem(t_mlxdata *app, float x, float y, float scale)
{
	float	dx;
	float	dy;
	float	max;

	x *= scale;
	y *= scale;
	app->map->size_x *= scale;
	app->map->size_y *= scale;
	dx = (float)((app->map->size_x - 1.0) - x);
	dy = (float)((app->map->size_y - 1.0) - y);
	max = MAX(MOD(dx), MOD(dy));
	dx /= max;
	dy /= max;
	while ((int)(app->map->size_x - x) || (int)(app->map->size_y - y))
	{
		setpixel(app, x, y, rgbcolor(255, 0, 0));
		x += dx;
		y += dy;
	}
	app->map->size_x /= scale;
	app->map->size_y /= scale;
	mlx_clear_window(app->app, app->wnd);
	mlx_put_image_to_window(app->app, app->wnd, app->img->img_ptr, 0, 0);
}

int	main(void)
{
	int			scale;
	t_mlxdata	*app;

	scale = 20;
	app = crt_mlxdata("../maps/test_maps/42.fdf", scale);
	brensenhem(app, 0, 0, scale);
	mlx_hook(app->wnd, 17, 1L<<3, exitapp, app);
	mlx_loop(app->app);
	return (0);
}
