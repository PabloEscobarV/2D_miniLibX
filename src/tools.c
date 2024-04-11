/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:46:37 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/11 12:00:54 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	*free_map(t_map	*crd)
{
	ft_free_d((void **)(crd->crd));
	free(crd);
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
