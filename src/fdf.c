/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:09:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/10 21:29:25 by blackrider       ###   ########.fr       */
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

t_mlxdata	*crt_mlxdata(const char *filename)
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
	data->wnd = mlx_new_window(data->app, MAX(SIZE_X, data->map->size_x * 3),
		MAX(SIZE_Y, data->map->size_y * 3), TITLE);
	data->img = malloc(sizeof(t_mlximg));
	if (!(data->wnd) || !(data->img))
		return (ft_free_mlxdata(data));
	data->img->img_ptr = mlx_new_image(data->app, data->map->size_x,
		data->map->size_y);
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

int	main(void)
{
	t_mlxdata	*app;

	app = crt_mlxdata("../maps/test_maps/42.fdf");
	mlx_hook(app->wnd, 17, 1L<<3, exitapp, app);
	mlx_loop(app->app);
	return (0);
}
