/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:53:00 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/17 13:55:54 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

long		ft_abs(long x)
{
	if (x < 0)
		return (-x);
	return (x);
}

long	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
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

int	sizematrix(char **mapstr)
{
	int	size;

	if (!mapstr)
		return (-1);
	size = 0;
	while (mapstr[size])
		++size;
	return (size);
}
