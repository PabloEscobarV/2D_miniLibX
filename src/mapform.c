/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:21:21 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/09 13:58:21 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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
		free(tmp);
		++tmp;
	}
	free(ptr);
	return (NULL);
}

int		sizematrix(char **mat)
{
	int	size;

	if (!mat)
		return (-1);
	size = 0;
	while (mat[size])
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

long	filesize(char *filename)
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

char	*maptostr(char filename)
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

char	**crtcharmap(char *filename)
{
	int		size;
	char	*tmp;
	char	**mat;
	char	***map;

	tmp = maptostr(filename);
	mat = ft_split(tmp, '\n');
	free(tmp);
	if (!mat)
		return (NULL);
	size = sizematrix(mat);
	map = malloc((size + 1) * sizeof(char **));
	if (!map)
		return (ft_free_d(mat));
	i = map;
	while (i)
	return (mat);
}
