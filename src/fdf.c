/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:13:06 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/04 11:23:35 by polenyc          ###   ########.fr       */
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
	mlx_destroy_image(app->mlxapp, app->img->img_ptr);
	mlx_destroy_window(app->mlxapp, app->mlxwindow);
	mlx_destroy_display(app->mlxapp);
	free(app->mlxapp);
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

	offset = app->img->line_len * y + x * app->img->bits_per_pixel / 8;
	*(unsigned int *)(offset + app->img->img_pixels) = color;
}

int	setcolorscreen(t_mlxdata *app, int color)
{
	for (int i = 0; i < SIZE_X; ++i)
		for (int j = 0; j < SIZE_Y; ++j)
			setpixel(app, i, j, color);
	mlx_clear_window(app->mlxapp, app->mlxwindow);
	mlx_put_image_to_window(app->mlxapp, app->mlxwindow, app->img->img_ptr, 0, 0);
	mlx_put_image_to_window(app->mlxapp, app->mlxwindow, app->pacman->img_ptr, SIZE_X / 2, SIZE_Y / 2);
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

	app.mlxapp = mlx_init();
	app.img = malloc(sizeof(t_mlximg));
	app.pacman = malloc(sizeof(t_mlximg));
	if (!(app.mlxapp))
	{
		perror("mlx init");
		exit (-1);
	}
	app.mlxwindow = mlx_new_window(app.mlxapp, SIZE_X, SIZE_Y, "WINDOW");
	app.img->img_ptr = mlx_new_image(app.mlxapp, SIZE_X, SIZE_Y);
	app.img->img_pixels = mlx_get_data_addr(app.img->img_ptr, &app.img->bits_per_pixel, &app.img->line_len, &app.img->endian);
	app.pacman->img_ptr = mlx_xpm_file_to_image(app.mlxapp, "Pac-Man/pac_closed.xpm", &app.pacman->img_width, &app.pacman->img_height);
	mlx_put_image_to_window(app.mlxapp, app.mlxwindow, app.img->img_ptr, 0, 0);
	mlx_put_image_to_window(app.mlxapp, app.mlxwindow, app.pacman->img_ptr, SIZE_X / 2, SIZE_Y / 2);
	mlx_hook(app.mlxwindow, 17, 1L<<3, closeevent, &app);
	mlx_key_hook(app.mlxwindow, setcolor, &app);
	mlx_loop(app.mlxapp);
	return (0);
}
