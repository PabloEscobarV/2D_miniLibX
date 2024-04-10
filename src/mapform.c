/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:21:21 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/10 14:25:12 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

void	*ft_free_d(void **ptr)
{
	void	**tmp;

	tmp = ptr;
	while(*tmp)
	{
		free(*tmp);
		++tmp;
	}
	free(ptr);
	return (NULL);
}

void	*ft_free_t(void ***ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			free(ptr[i][j]);
			++j;
		}
		free(ptr[i]);
		++i;
	}
	free(ptr);
	return (NULL);
}

int		sizematrix(char **mapstr)
{
	int	size;

	if (!mapstr)
		return (-1);
	size = 0;
	while (mapstr[size])
		++size;
	return (size);
}

t_mapd  *create_mapd(long z, long color)
{
    t_mapd  *tmp;

    tmp = malloc(sizeof(t_mapd));
	if (!tmp)
		return (NULL);
	tmp->z = z;
	tmp->color = color;
	return (tmp);
}

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
	// for (int i = 0; map[i]; ++i)
	// {
	// 	for (int j = 0; map[i][j]; ++j)
	// 	{
	// 		printf("%s", map[i][j]);
	// 		if (ft_strlen(map[i][j]) > 1)
	// 			printf(" ");
	// 		else
	// 			printf("  ");
	// 	}
	// 	printf("\n");
	// }
	// printf("\n-----\n");
	return (map);
}

long	tda_size(char ***map)
{
	long	size;

	if (!map)
		return (-1);
	size = 0;
	while (map[size])
		++size;
	return (size);
}

t_mapd	*crtmapd(char **mapchar, t_crd *map)
{
	int		i;
	char	**tmp;
	t_mapd	*data;

	if (map->size_y != sizematrix(mapchar))
		return (NULL);
	data = malloc(map->size_y * sizeof(t_mapd));
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

t_crd	*createmap(const char *filename)
{
	int		i;
	char	***charmap;
	t_crd	*map;

	charmap = crtcharmap(filename);
	map = malloc(sizeof(t_crd));
	if (!map)
		return (NULL);
	map->size_y = sizematrix(*charmap);
	map->size_x = tda_size(charmap);
	map->crd = malloc((map->size_x + 1) * sizeof(t_mapd *));
	i = 0;
	while (i < map->size_x)
	{
		map->crd[i] = crtmapd(charmap[i], map);
		++i;
	}
	map->crd[map->size_x] = NULL;
	ft_free_t((void ***)charmap);
	return (map);
}

void	*free_crd(t_crd	*crd)
{
	ft_free_d((void **)(crd->crd));
	free(crd);
}

int	main(void)
{
	t_crd	*crd;

	crd = createmap("../maps/test_maps/elem-fract.fdf");
	for (int i = 0; i < crd->size_x; ++i)
	{
		for (int j = 0; j < crd->size_y; ++j)
		{
			printf("%d,%d\t", crd->crd[i][j].z, crd->crd[i][j].color);
		}
		printf("\n");
	}
	free_crd(crd);
	return (0);
}
