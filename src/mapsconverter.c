/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapsconverter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:53:39 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/01 21:19:30 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <fcntl.h>

int	mapsconvert(char *filename)
{
	int	file;

	file = open(filename, O_RDONLY);
}