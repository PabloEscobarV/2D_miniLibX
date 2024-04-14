/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:21:21 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/14 22:56:38 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

long	filesize(const char *filename)
{
	long	size;
	char	tmp;
	int		file;

	file = open(filename, O_RDONLY);
	if (file < 3)
		return (-1);
	size = 0;
	while (read(file, &tmp, sizeof(char)))
		++size;
	close(file);
	return (size);
}

char	*maptostr(const char *filename)
{
	long	size;
	int		file;
	char	*tmp;

	size = filesize(filename);
	if (size < 0)
		return (NULL);
	file = open(filename, O_RDONLY);
	tmp = malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	if (read(file, tmp, size) < 0)
	{
		free(tmp);
		return (NULL);
	}
	tmp[size] = '\0';
	close(file);
	return (tmp);
}

char	**crtcharmat(const char *filename)
{
	char	*tmp;
	char	**mapstr;

	tmp = maptostr(filename);
	if (!tmp)
		return (NULL);
	mapstr = ft_split(tmp, '\n');
	free(tmp);
	if (!mapstr)
		return (NULL);
	return (mapstr);
}

char	***crtcharmap(const char *filename)
{
	int		i;
	int		size;
	char	**mapstr;
	char	***map;

	mapstr = crtcharmat(filename);
	if (!mapstr)
		return (NULL);
	size = sizematrix(mapstr);
	map = malloc((size + 1) * sizeof(char **));
	if (!map)
		return ((char ***)ft_free_d((void **)mapstr));
	i = 0;
	while (i < size)
	{
		map[i] = ft_split(mapstr[i], ' ');
		++i;
	}
	map[size] = NULL;
	ft_free_d((void **)mapstr);
	return (map);
}

t_map	*createmap(const char *filename)
{
	int		i;
	char	***charmap;
	t_map	*map;

	charmap = crtcharmap(filename);
	if (!charmap)
		return (NULL);
	map = malloc(sizeof(t_map));
	map->size_x = sizematrix(*charmap);
	map->size_y = tda_size(charmap);
	map->crd = malloc((map->size_y + 1) * sizeof(t_mapd *));
	i = 0;
	while (i < (int)map->size_y)
	{
		map->crd[i] = crtmapd(charmap[i], map);
		if (!map->crd[i])
		{
			ft_free_t((void ***)charmap);
			return (free_map(map));
		}
		++i;
	}
	map->crd[map->size_y] = NULL;
	ft_free_t((void ***)charmap);
	return (map);
}
