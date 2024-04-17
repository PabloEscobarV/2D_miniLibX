/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:46:37 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/17 13:55:49 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include "../minilibx-linux/mlx.h"

void	*free_map(t_map	*crd)
{
	ft_free_d((void **)(crd->crd));
	free(crd);
	return (NULL);
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
