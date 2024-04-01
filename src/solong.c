/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:19:03 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/01 15:02:02 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>

#define SIZE_X 800
#define SIZE_Y 800

typedef unsigned char uchar;

typedef struct s_bgimg
{
	void	*img;
	int		img_width;
	int		img_height;
}			t_bgimg;


typedef	struct s_mlximg
{
	void	*img_ptr;
	char	*img_pixels;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
	int		img_width;
	int		img_height;
}				t_mlximg;


typedef struct s_mlxdata
{
	void		*mlxapp;
	void		*mlxwindow;
	t_mlximg	*mlximg;
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
			pixel_put(data->mlximg, i, j, color);
	return (0);
}

int	handle_input(int keysum, t_mlxdata *data)
{
	if (keysum == XK_Escape)
	{
		printf("The %d key (EXC) has been pressed\n", keysum);
		// mlx_destroy_image(data->mlxapp, data->mlximg->img_ptr);
		mlx_destroy_window(data->mlxapp, data->mlxwindow);
		mlx_destroy_display(data->mlxapp);
		free(data->mlxapp);
		exit(1);
	}
	printf("The %d has been pressed\n", keysum);
	// if (keysum == XK_space)
	// 	sleep(1);
	// if (keysum == XK_r)
	// 	color_screen(data, encode_rgb(255, 0, 0));
	// if (keysum == XK_g)
	// 	color_screen(data, encode_rgb(0, 255, 0));
	// if (keysum == XK_b)
	// 	color_screen(data, encode_rgb(0, 0, 255));
	// // mlx_put_image_to_window(data->mlxapp, data->mlxwindow, data->mlximg->img_ptr, 0, 0);
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
	mlx_destroy_image(data->mlxapp, data->mlximg->img_ptr);
	mlx_destroy_window(data->mlxapp, data->mlxwindow);
	mlx_destroy_display(data->mlxapp);
	free(data->mlximg);
	free(data->mlxapp);
	exit(0);
}

int	main(void)
{
	t_mlxdata	data;

	data.mlximg = malloc(sizeof(t_mlximg));
	data.mlxapp = mlx_init();
	if (!(data.mlxapp))
	{
		perror("mlx init");
		exit(-1);
	}
	data.mlxwindow = mlx_new_window(data.mlxapp, SIZE_X + 100, SIZE_Y + 100, "DARROVA!!");
	data.mlximg->img_ptr = mlx_xpm_file_to_image(data.mlxapp, "/home/blackrider/wolfsburg/2D_miniLibX/background/bgimg_n.xpm",
		&data.mlximg->img_width, &data.mlximg->img_height);
	mlx_put_image_to_window(data.mlxapp, data.mlxwindow, data.mlximg->img_ptr, 0, 0);
	mlx_key_hook(data.mlxwindow, handle_input, &data);
	mlx_mouse_hook(data.mlxwindow, cross_close, &data);
	mlx_hook(data.mlxwindow, 17, 1L<<3, close_event, &data);
	mlx_loop(data.mlxapp);
	return (0);
}


// int	main(void)
// {
// 	t_mlxdata	data;
// 	t_bgimg		bgimg;

// 	data.mlximg = malloc(sizeof(t_mlximg));
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
// 	// data.mlximg->img_ptr = mlx_new_image(data.mlxapp, SIZE_X, SIZE_Y);
// 	// data.mlximg->img_pixels = mlx_get_data_addr(data.mlximg->img_ptr, 
// 		// &data.mlximg->bits_per_pixel, &data.mlximg->line_len, &data.mlximg->endian);
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