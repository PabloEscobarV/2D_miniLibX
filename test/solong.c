/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:19:03 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/04 10:24:47 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>

typedef unsigned char uchar;

typedef struct s_bgimg
{
	void	*img;
	int		img_width;
	int		img_height;
}			t_img;


typedef	struct s_mlximg
{
	void	*img_ptr;
	char	*img_pixels;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
}				t_mlximg;


typedef struct s_mlxdata
{
	void		*mlxapp;
	void		*mlxwindow;
	t_mlximg	*bgimg;
	t_mlximg	*pacman;
}				t_mlxdata;

void	pixel_put(t_mlximg *img_ptr, int x, int y, int color)
{
	int	offset;

	offset = img_ptr->line_len * y + x * img_ptr->bits_per_pixel / 8;
	*(unsigned int *)(offset + img_ptr->img_pixels) = color;
}

int	encode_rgb(uchar red, uchar green, uchar blue)
{
	return (red << 16 | green << 8 | blue);
}

int	color_screen(t_mlxdata *data, int color)
{
	for (int i = 0; i < SIZE_X; ++i)
		for (int j = 0; j < SIZE_Y; ++j)
			pixel_put(data->bgimg, i, j, color);
	return (0);
}

int	handle_input(int keysum, t_mlxdata *data)
{
	printf("The %d has been pressed\n", keysum);
	if (keysum == XK_w || keysum == XK_Up)
	{
		mlx_clear_window(data->mlxapp, data->mlxwindow);
		mlx_put_image_to_window(data->mlxapp, data->mlxwindow, data->bgimg->img_ptr, 0, 0);
		data->pacman->y = data->pacman->y - 5;
		mlx_put_image_to_window(data->mlxapp, data->mlxwindow, data->pacman->img_ptr,
			data->pacman->x, data->pacman->y);
	}
	if (keysum == XK_s || keysum == XK_Down)
	{
		mlx_clear_window(data->mlxapp, data->mlxwindow);
		mlx_put_image_to_window(data->mlxapp, data->mlxwindow, data->bgimg->img_ptr, 0, 0);
		data->pacman->y = data->pacman->y + 5;
		mlx_put_image_to_window(data->mlxapp, data->mlxwindow, data->pacman->img_ptr,
			data->pacman->x, data->pacman->y);
	}
	if (keysum == XK_d || keysum == XK_Right)
	{
		mlx_clear_window(data->mlxapp, data->mlxwindow);
		mlx_put_image_to_window(data->mlxapp, data->mlxwindow, data->bgimg->img_ptr, 0, 0);
		data->pacman->x = data->pacman->x + 5;
		mlx_put_image_to_window(data->mlxapp, data->mlxwindow, data->pacman->img_ptr,
			data->pacman->x, data->pacman->y);
	}
	if (keysum == XK_a || keysum == XK_Left)
	{
		mlx_clear_window(data->mlxapp, data->mlxwindow);
		mlx_put_image_to_window(data->mlxapp, data->mlxwindow, data->bgimg->img_ptr, 0, 0);
		data->pacman->x = data->pacman->x - 5;
		mlx_put_image_to_window(data->mlxapp, data->mlxwindow, data->pacman->img_ptr,
			data->pacman->x, data->pacman->y);
	}
	// if (keysum == XK_Escape)
	// {
	// 	printf("The %d key (EXC) has been pressed\n", keysum);
	// 	// mlx_destroy_image(data->mlxapp, data->bgimg->img_ptr);
	// 	mlx_destroy_window(data->mlxapp, data->mlxwindow);
	// 	mlx_destroy_display(data->mlxapp);
	// 	free(data->mlxapp);
	// 	exit(1);
	// }
	// if (keysum == XK_space)
	// 	sleep(1);
	// if (keysum == XK_r)
	// 	color_screen(data, encode_rgb(255, 0, 0));
	// if (keysum == XK_g)
	// 	color_screen(data, encode_rgb(0, 255, 0));
	// if (keysum == XK_b)
	// 	color_screen(data, encode_rgb(0, 0, 255));
	// // mlx_put_image_to_window(data->mlxapp, data->mlxwindow, data->bgimg->img_ptr, 0, 0);
	return (0);
}

int	cross_close(int button, int x, int y, t_mlxdata *data)
{
	printf("button:\t%d\n", button);
	if (button == 1)
		printf("Button:\t%d\tx: %d\ty: %d\n", button, x, y);
	return (0);
}

int	close_event(t_mlxdata *data)
{
	printf("Cross button was prassed!!!\n-----EXIT!!!----\n");
	mlx_destroy_image(data->mlxapp, data->bgimg->img_ptr);
	mlx_destroy_window(data->mlxapp, data->mlxwindow);
	mlx_destroy_display(data->mlxapp);
	free(data->bgimg);
	free(data->mlxapp);
	exit(0);
}

int	main(void)
{
	t_mlxdata	data;

	data.bgimg = malloc(sizeof(t_mlximg));
	data.pacman = malloc(sizeof(t_mlximg));
	data.mlxapp = mlx_init();
	if (!(data.mlxapp))
	{
		perror("mlx init");
		exit(-1);
	}
	data.mlxwindow = mlx_new_window(data.mlxapp, SIZE_X + 100, SIZE_Y + 100, "DARROVA!!");
	data.bgimg->img_ptr = mlx_xpm_file_to_image(data.mlxapp, "background/background.xpm",
		&data.bgimg->img_width, &data.bgimg->img_height);
	data.pacman->img_ptr = mlx_xpm_file_to_image(data.mlxapp, "Pac-Man/pac_closed.xpm",
		&data.pacman->img_width, &data.pacman->img_height);
	data.pacman->x = SIZE_X / 2;
	data.pacman->y = SIZE_Y - 100;
	mlx_put_image_to_window(data.mlxapp, data.mlxwindow, data.bgimg->img_ptr, 0, 0);
	mlx_put_image_to_window(data.mlxapp, data.mlxwindow, data.pacman->img_ptr, data.pacman->x, data.pacman->y);
	// mlx_key_hook(data.mlxwindow, handle_input, &data);
	mlx_mouse_hook(data.mlxwindow, cross_close, &data);
	mlx_hook(data.mlxwindow, 2, 1L, handle_input, &data);
	mlx_hook(data.mlxwindow, 17, 1L<<3, close_event, &data);
	mlx_loop(data.mlxapp);
	return (0);
}


// int	main(void)
// {
// 	t_mlxdata	data;
// 	t_img		bgimg;

// 	data.bgimg = malloc(sizeof(t_mlximg));
// 	data.mlxapp = mlx_init();
// 	if (!(data.mlxapp))
// 	{
// 		perror("mlx init");
// 		exit(-1);
// 	}
// 	data.mlxwindow = mlx_new_window(data.mlxapp, SIZE_X + 100, SIZE_Y + 100, "DARROVA!!");
// 	bgimg.img = mlx_xpm_file_to_image(data.mlxapp, "/home/blackrider/wolfsburg/2D_miniLibX/background/bgimg_n.xpm", &bgimg.img_width, &bgimg.img_height);
// 	if (!(bgimg.img))
// 		printf("ERROR!!! Bad image PATH\n");
// 	// data.bgimg->img_ptr = mlx_new_image(data.mlxapp, SIZE_X, SIZE_Y);
// 	// data.bgimg->img_pixels = mlx_get_data_addr(data.bgimg->img_ptr, 
// 		// &data.bgimg->bits_per_pixel, &data.bgimg->line_len, &data.bgimg->endian);
// 	mlx_put_image_to_window(data.mlxapp, data.mlxwindow, bgimg.img, 0, 0);
// 	// mlx_mouse_hook(data.mlxwindow, cross_close, &data);
// 	// mlx_key_hook(data.mlxwindow, handle_input, &data);
// 	mlx_loop(data.mlxapp);
// 	return (0);
// }

// typedef struct	s_data {
// 	void	*img_ptr;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }			t_data;

// typedef struct	s_mlx_data {
// 	void	*app;
// 	void	*window;
// 	int		color;
// }			t_mlx_data;

// int	encode_rgb(uchar red, uchar green, uchar blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }

// int	color_screen(t_mlx_data *data, int color)
// {
// 	for (int i = 0; i < SIZE_X; ++i)
// 		for (int j = 0; j < SIZE_Y; ++j)
// 			mlx_pixel_put(data->app, data->window, i, j, color);
// 	return (0);
// }

// int	handle_input(int keysum, t_mlx_data *data)
// {
// 	if (keysum == XK_Escape)
// 	{
// 		printf("The %d key (EXC) has been pressed\n", keysum);
// 		mlx_destroy_window(data->app, data->window);
// 		mlx_destroy_display(data->app);
// 		free(data->app);
// 		exit(1);
// 	}
// 	printf("The %d has been pressed\n", keysum);
// 	if (keysum == XK_space)
// 		sleep(1);
// 	if (keysum == XK_r)
// 		color_screen(data, encode_rgb(255, 0, 0));
// 	if (keysum == XK_g)
// 		color_screen(data, encode_rgb(0, 255, 0));
// 	if (keysum == XK_b)
// 		color_screen(data, encode_rgb(0, 0, 255));
// 	return (0);
// }

// int	change_color(t_mlx_data *data)
// {
// 	mlx_string_put(data->app, data->window, 150, 150, data->color, "ERROR!!!!");
// 	if (data->color == 0xFF0000)
// 	{
// 		data->color = 0x00FF00;
// 		return (0);
// 	}
// 	if (data->color == 0x00FF00)
// 	{
// 		data->color = 0x000FF0;
// 		return (0);
// 	}
// 		data->color = 0xFF0000;
// 	return (0);
// }

// int main(void)
// {
// 	t_mlx_data	app;

// 	app.color = 0xFF0000;
// 	app.app = mlx_init();
// 	app.window = mlx_new_window(app.app, 1000, 1000, "Darrova!!!");
// 	mlx_key_hook(app.window, handle_input, &app);
// 	mlx_loop_hook(app.app, change_color, &app);
// 	mlx_loop(app.app);
// 	mlx_destroy_window(app.app, app.window);
//     mlx_destroy_display(app.app);
//     free(app.app);
//     return (0);
// }