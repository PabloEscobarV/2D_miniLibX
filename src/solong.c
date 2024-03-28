/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:19:03 by polenyc           #+#    #+#             */
/*   Updated: 2024/03/28 18:02:03 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#define XK_Escape 65307

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct	s_mlx_data {
	void	*app;
	void	*window;
}			t_mlx_data;

int	handle_input(int keysum, t_mlx_data *data)
{
	if (keysum == XK_Escape)
	{
		printf("The %d key (EXC) has been pressed\n", keysum);
		mlx_destroy_window(data->app, data->window);
		mlx_destroy_display(data->app);
		exit(1);
	}
	printf("The %d has been pressed\n", keysum);
	return (0);
}

int main(void)
{
	t_mlx_data	app;

	app.app = mlx_init();
	app.window = mlx_new_window(app.app, 1000, 1000, "Darrova!!!");
	mlx_key_hook(app.window, handle_input, &app);
	mlx_loop(app.app);
    mlx_destroy_display(app.app);
    free(app.app);
    return (0);
}