/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapget.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:55:16 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/02 14:58:42 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../get_next_line/get_next_line_bonus.h"
#include "../hdrs/so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	**return_free(void *ptr, int file)
{
	if (file > 2)
		close(file);
	if (ptr)
		free(ptr);
	return (NULL);
}

void	*freematrix(void **ptr)
{
	void	**tmp;

	if (!ptr)
		return (NULL);
	tmp = ptr;
	while (*tmp)
	{
		free(*tmp);
		++tmp;
	}
	free(ptr);
	return (NULL);
}

int		sizeptr(char **map)
{
	int	size;

	if (!map)
		return (-1);
	size = 0;
	while (map[size])
		++size;
	return (size);
}

char	**mapcopy(char *filename)
{
	int		file;
	char	*data;
	char	*tmp;
	char	**map;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return (NULL);
	data = NULL;
	tmp = get_next_line(file);
	while (tmp)
	{
		data = ft_strjoinfree(data, tmp, 2);
		if (!data)
			return ((char **)return_free(data, file));
		tmp = get_next_line(file);
	}
	map = ft_split(data, '\n');
	free(data);
	close(file);
	return (map);
}

char	***maptostr(char *filename)
{
	int		i;
	int		size;
	char	**tmp;
	char	***map;

	tmp = mapcopy(filename);
	size = sizeptr(tmp);
	map = malloc((size + 1) * sizeof(char **));
	if (!map)
		return (NULL);
	while(tmp[i])
	{
		map[i] = ft_split(tmp[i], ' ');
		++i;
	}
	map[size] = NULL;
	freematrix((void **)tmp);
	return (map);
}



// int		**mapmatrix(char *filename)
// {
// 	char	***strmap;
// 	char	***tmp;
// 	int		**map;

// 	strmap = maptostr(filename);
// 	if (!strmap)
// 		return (NULL);
// 	tmp = strmap;
// 	while (*tmp)
// 	{

// 	}
// 	return ();
// }

int	main()
{
	char	filename[1024];
	char	***data;

	printf("Enter the filename:\n");
	scanf("%s", filename);
	data = maptostr(filename);
	if (!data)
	{
		perror("Bad file operation");
		exit(-1);
	}
	while (*data)
	{
		while (**data)
		{
			printf("%s", **data);
			printf("|");
			++(*data);
		}
		printf("\n");
		++data;
	}
	printf("\n");
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