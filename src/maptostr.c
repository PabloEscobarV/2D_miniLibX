/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:03:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/03 14:42:41 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

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
	size_t	size;
	int		file;
	char	*data;
	char	**map;

	size = ft_filesize(filename);
	file = open(filename, O_RDONLY);
	data = malloc((size + 1) * sizeof(char));
	if (file < 0 || !data)
		return (NULL);
	read(file, data, size);
    data[size] = '\0';
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
	i = 0;
	while(tmp[i])
	{
		map[i] = ft_split(tmp[i], ' ');
		++i;
	}
	map[size] = NULL;
	freedub((void **)tmp);
	return (map);
}
