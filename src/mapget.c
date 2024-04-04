/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapget.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:55:16 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/04 10:20:37 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include <stdio.h>

t_map		*crtt_map(int x, int y, int alt, long color)
{
	t_map	*tmp;

	tmp = malloc(sizeof(t_map));
	if (!tmp)
		return (NULL);
	tmp->z = alt;
	tmp->color = color;
	tmp->x = x;
	tmp->y =y;
	return (tmp);
}

t_map	*sett_map(t_map *data, char *str, int x, int y)
{
	char	**strdata;
	char	**tmp;

	if (!data)
		data = crtt_map(0, 0, 0, 0);
	if (!data)
		return (NULL);
	tmp = ft_split(str, ',');
	strdata = tmp;
	data->x = x;
	data->y = y;
	data->z = ft_atoi(*tmp);
	if (!(*(tmp + 1)))
	{
		freedub
	((void **)tmp);
		return (data);
	}
	if (**(tmp + 1) == '0' && !ft_isdigit(*(*(tmp + 1) + 1)))
		data->color = ft_atoi_base(*(tmp + 1), HEX_BASE_L);
	else
		data->color = ft_atoi(*(tmp + 1));
	freedub((void **)tmp);
	return (data);
}

t_llist		*crtlstmap(t_llist **map, char ***str)
{
	t_map	*tmp;
	int		x;
	int		y;

	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			tmp = sett_map(NULL, str[y][x], x, y);
			llistadd_back(map, llistnewnode(tmp));
			++x;
		}
		++y;
	}
	return (*map);
}

t_llist		*maptollst(char *filename)
{
	char	***str;
	t_llist	*map;

	str = maptostr(filename);
	if (!str)
		return (NULL);
	map = NULL;
	crtlstmap(&map, str);
	freetriple((void ***)str);
	return (map);
}

void	printdata(void *ptr)
{
	t_map	*data;

	data = (t_map *)ptr;
	printf("x: %d\ty: %d\tz: %d\tcolor: %d\n",
		data->x, data->y, data->z, (int)data->color);
}

void	delfunc(void *data)
{
	free(data);
}

int	main()
{
	t_llist	*map;
	size_t	*size;
	char	filename[1024];
	char	***data;

	printf("Enter the filename:\n");
	scanf("%s", filename);
	// data = maptostr(filename);
	// if (!data)
	// {
	// 	perror("Bad file operation");
	// 	exit(-1);
	// }
	// size = sizematrix(data);
	// printf("rows: %d\tcolums: %d\tcount data: %d\n", size[0], size[1], size[2]);
	// while (*data)
	// {
	// 	while (**data)
	// 	{
	// 		printf("%s", **data);
	// 		printf("\t");
	// 		++(*data);
	// 	}
	// 	printf("\n");
	// 	++data;
	// }
	map = maptollst(filename);
	llistiter(map, printdata);
	llistclear(&map, delfunc);
	return (0);
}

// int		checksymbols(char ch)
// {
// 	if (ch != '\n' && ch != 'C' && ch != 'E' && ch != 'P'
// 		&& ch != '0' && ch != '1' && ch != 'G')
// 		return (-1);
// 	if (ch == 'P')
// 		return (255);
// 	return (0);
// }

// int		checkdata(int *size, uchar *cntr_pe, char ch)
// {
// 	*cntr_pe += checksymbols(ch);
// 	if (*cntr_pe != 0 && *cntr_pe != 255)
// 		return (1);
// 	++(size[0]);
// 	if (ch == '\n')
// 	{
// 		++(size[1]);
// 		if (size[1] > 1 && size[0] % size[1])
// 			return (1);
// 	}
// 	return (0);
// }

// int		*mapmartrixsize(char *filename)
// {
// 	int		file;
// 	int		*size;
// 	char	tmp;
// 	uchar	cntr_pe;

// 	size = malloc(2 * sizeof(int));
// 	file = open(filename, O_RDONLY);
// 	if (file < 0 || !size)
// 		return (return_free(filename, size));
// 	size[0] = 0;
// 	size[1] = 0;
// 	cntr_pe = 0;
// 	while (read(file, &tmp, sizeof(tmp)) > 0)
// 	{
// 		if (checkdata(size, &cntr_pe, tmp))
// 			return (return_free(filename, size));
// 		printf("i: %d\ttest: %s", );
// 	}
// 	if (tmp != '\n')
// 		++(size[1]);
// 	close(file);
// 	return (size);
// }

// char	**mapcopy(char *filename, int *size)
// {
// 	int		size_str;
// 	int		i;
// 	int		file;
// 	char	**mapmatrix;

// 	file = open(filename, O_RDONLY);
// 	mapmatrix = malloc((size[1] + 1) * sizeof(char *));
// 	if (!mapmatrix || !size || file < 0)
// 		return (NULL);
// 	size_str = (size[0] - size[1]) / size[1] + 1;
// 	i = 0;
// 	while (i < size[1])
// 	{
// 		mapmatrix[i] = malloc((1 + size_str) * sizeof(char));
// 		if (read(file, mapmatrix[i], size_str) < 0)
// 			break ;
// 		++i;
// 	}
// 	mapmatrix[size[1]] = NULL;
// 	close(file);
// 	return (mapmatrix);
// }


// size_t		*sizematrix(char ***map)
// {
// 	size_t	*size;

// 	size = ft_calloc(3, sizeof(size_t));
// 	if (!size || !map)
// 		return (NULL);
// 	while (map[0][size[1]])
// 		++(size[1]);
// 	while (map[size[0]])
// 		++(size[0]);
// 	size[2] = 2;
// 	return (size);
// }

// int		***createintmap(char ***str)
// {
// 	int		i;
// 	size_t	*sizemap;
// 	int		***map;

// 	sizemap = sizematrix(str);
// 	map = ft_calloc(sizemap[0] + 1, sizeof(int **));
// 	if (!map)
// 		return (NULL);
// 	while ((sizemap[0])--)
// 	{
// 		map[sizemap[0]] = ft_calloc(sizemap[1] + 1, sizeof(int *));
// 		i = 0;
// 		while (i < sizemap[1])
// 		{
// 			map[sizemap[0]][i] = ft_calloc(sizemap[3], sizeof(int));
// 			++i;
// 		}
// 	}
// 	return (map);
// }