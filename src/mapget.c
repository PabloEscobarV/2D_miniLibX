/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapget.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:55:16 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/02 12:35:18 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <fcntl.h>

void	*return_free(char *filename, void *ptr)
{
	free(ptr);
	return (NULL);
}

int		checksymbols(char ch)
{
	if (ch != '\n' && ch != 'C' && ch != 'E' && ch != 'P'
		&& ch != '0' && ch != '1')
		return (-1);
	if (ch == 'P')
		return (255);
	return (0);
}

int		checkdata(int *size, uchar *cntr_pe, char ch)
{
	*cntr_pe += checksymbols(ch);
	if (*cntr_pe != 0 && *cntr_pe != 255)
		return (1);
	++(size[0]);
	if (ch == '\n')
	{
		++(size[1]);
		if (size[1] > 1 && size[0] % size[1])
			return (1);
	}
	return (0);
}

int		*mapmartrixsize(char *filename)
{
	int		file;
	int		*size;
	char	tmp;
	uchar	cntr_pe;

	size = malloc(2 * sizeof(int));
	file = open(filename, O_RDONLY);
	if (file < 0 || !size)
		return (return_free(filename, size));
	size[0] = 0;
	size[1] = 0;
	cntr_pe = 0;
	while (read(file, &tmp, sizeof(tmp)) > 0)
		if (checkdata(size, &cntr_pe, tmp))
			return (return_free(filename, size));
	close(file);
	return (size);
}

char	**mapcopy(char *filename, int *size)
{
	int		size_str;
	int		i;
	int		file;
	char	**mapmatrix;

	file = open(filename, O_RDONLY);
	mapmatrix = malloc((size[1] + 1) * sizeof(char *));
	if (!mapmatrix || !size || file < 0)
		return (NULL);
	size_str = (size[0] - size[1]) / size[1] + 1;
	i = 0;
	while (i < size[1])
	{
		mapmatrix[i] = malloc((1 + size_str) * sizeof(char));
		if (read(file, mapmatrix[i], size_str) < 0)
			break ;
		++i;
	}
	mapmatrix[size[1]] = NULL;
	close(file);
	return (mapmatrix);
}

char	**mapmatrix(char *filename)
{
	return (mapcopy(filename, mapmartrixsize(filename)));
}

int	main()
{
	int		*size;
	char	filename[1024];
	char	**map;

	printf("Enter the filename:\n");
	scanf("%s", filename);
	size = mapmartrixsize(filename);
	if (!size)
	{
		perror("Bad file operation");
		exit(-1);
	}
	printf("file size: %d\tcount of new lines symbols: %d\n", size[0], size[1]);
	free(size);
	map = mapmatrix(filename);
	if (!map)
	{
		perror("Bad file operation");
		exit(-1);
	}
	while (*map)
	{
		printf("%s", *map);
		++map;
	}
	printf("\n");
	return (0);
}