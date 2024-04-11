/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:21:21 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/11 12:56:06 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*maptostr(const char *filename)
{
	long	size;
	int		file;
	char	*tmp;

	size = filesize(filename);
	file = open(filename, O_RDONLY);
	tmp = malloc((size + 1) * sizeof(char));
	if (file < 3 || !tmp)
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

t_mapd	*crtmapd(char **mapchar, t_map *map)
{
	int		i;
	char	**tmp;
	t_mapd	*data;

	if (map->size_x != sizematrix(mapchar))
		return (NULL);
	data = malloc(map->size_x * sizeof(t_mapd));
	if (!data)
		return (NULL);
	i = 0;
	while (mapchar[i])
	{
		tmp = ft_split(mapchar[i], ',');
		(data + i)->z = ft_atoi(*tmp);
		(data + i)->color = ft_atoi_base(*(tmp + 1), HEX_BASE_L);
		ft_free_d((void **)tmp);
		++i;
	}
	return (data);
}

t_map	*createmap(const char *filename)
{
	int		i;
	char	***charmap;
	t_map	*map;

	charmap = crtcharmap(filename);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->size_x = sizematrix(*charmap);
	map->size_y = tda_size(charmap);
	map->crd = malloc((map->size_y + 1) * sizeof(t_mapd *));
	i = 0;
	while (i < map->size_y)
	{
		map->crd[i] = crtmapd(charmap[i], map);
		++i;
	}
	map->crd[map->size_y] = NULL;
	ft_free_t((void ***)charmap);
	return (map);
}

// int	main(void)
// {
// 	t_map	*crd;

// 	crd = createmap("../maps/test_maps/50-4.fdf");
// 	for (int i = 0; i < crd->size_y; ++i)
// 	{
// 		for (int j = 0; j < crd->size_x; ++j)
// 		{
// 			printf("%d,%d\t", crd->crd[i][j].z, crd->crd[i][j].color);
// 		}
// 		printf("\n");
// 	}
// 	free_map(crd);
// 	return (0);
// }
