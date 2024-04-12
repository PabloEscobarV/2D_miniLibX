/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:13:06 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/11 12:01:42 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <unistd.h>

int	closeevent(t_mlxdata *app)
{
	printf("Cross button was prassed!!!\n-----EXIT!!!----\n");
	mlx_destroy_image(app->app, app->img->img_ptr);
	mlx_destroy_window(app->app, app->wnd);
	mlx_destroy_display(app->app);
	free(app->app);
	free(app->img);
	exit(0);
	return (-1);
}

int	rgb_code(t_uchr red, t_uchr green, t_uchr blue)
{
	return (red << 16 | green << 8 | blue);
}

void	setpixel(t_mlxdata *app, int x, int y, int color)
{
	int	offset;

	offset = app->img->size_line * y + x * app->img->bits_per_pixel / 8;
	*(unsigned int *)(offset + app->img->img_pixels) = color;
}

int	setcolorscreen(t_mlxdata *app, int color)
{
	for (int i = 0; i < SIZE_X; ++i)
		for (int j = 0; j < SIZE_Y; ++j)
			setpixel(app, i, j, color);
	mlx_clear_window(app->app, app->wnd);
	mlx_put_image_to_window(app->app, app->wnd, app->img->img_ptr, 0, 0);
	mlx_put_image_to_window(app->app, app->wnd, app->pacman->img_ptr, SIZE_X / 2, SIZE_Y / 2);
	return (0);
}

int setcolor(int keysum, t_mlxdata *app)
{
	if (keysum == XK_Escape)
		return (closeevent(app));
	if (keysum == XK_r)
		setcolorscreen(app, rgb_code(255, 0, 0));
	if (keysum == XK_b)
		return (setcolorscreen(app, rgb_code(0, 0, 255)));
	if (keysum == XK_g)
		return (setcolorscreen(app, rgb_code(0, 255, 0)));
	return (0);
}

int	main()
{
	t_mlxdata	app;

	app.app = mlx_init();
	app.img = malloc(sizeof(t_mlximg));
	app.pacman = malloc(sizeof(t_mlximg));
	if (!(app.app))
	{
		perror("mlx init");
		exit (-1);
	}
	app.wnd = mlx_new_window(app.app, SIZE_X, SIZE_Y, "WINDOW");
	app.img->img_ptr = mlx_new_image(app.app, SIZE_X, SIZE_Y);
	app.img->img_pixels = mlx_get_data_addr(app.img->img_ptr, &app.img->bits_per_pixel, &app.img->size_line, &app.img->endian);
	app.pacman->img_ptr = mlx_xpm_file_to_image(app.app, "Pac-Man/pac_closed.xpm", &app.pacman->img_width, &app.pacman->img_height);
	mlx_put_image_to_window(app.app, app.wnd, app.img->img_ptr, 0, 0);
	mlx_put_image_to_window(app.app, app.wnd, app.pacman->img_ptr, SIZE_X / 2, SIZE_Y / 2);
	mlx_hook(app.wnd, 17, 1L<<3, closeevent, &app);
	mlx_key_hook(app.wnd, setcolor, &app);
	mlx_loop(app.app);
	return (0);
}
