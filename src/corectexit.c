/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corectexit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:19:44 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/16 13:30:56 by blackrider       ###   ########.fr       */
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
	free(data->crd);
	free(data->color);
	free(data);
	return (NULL);
}

int	exitapp(void *app)
{
	ft_free_mlxdata((t_mlxdata *)app);
	exit(0);
	return (0);
}
