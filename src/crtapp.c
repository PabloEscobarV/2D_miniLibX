/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crtapp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:34:25 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/12 13:08:25 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include "../minilibx-linux/mlx.h"

void	*ft_free_mlxdata(t_mlxdata	*data)
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
	free(data->sc);
	free(data);
	return (NULL);
}

t_mlxdata	*newmlxdata(void)
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
	if (!data || !map || !sc)
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
			&data->img->bits_per_pixel, &data->img->size_line,
			&data->img->endian);
	if (!(data->img->img_ptr) || !(data->img->img_pixels))
		return (ft_free_mlxdata(data));
	data->sc = sc;
	return (data);
}

int	exitapp(void *app)
{
	ft_free_mlxdata((t_mlxdata *)app);
	exit(0);
	return (0);
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
