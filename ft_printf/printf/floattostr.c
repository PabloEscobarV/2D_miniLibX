/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floattostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:49:25 by polenyc           #+#    #+#             */
/*   Updated: 2024/02/09 20:55:16 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdlib.h>
#include <limits.h>

char	*p_float(double n, const char *base, char *str, double count)
{
	int			size;

	size = ft_strlen(base);
	n *= size;
	if (n - (long)n == 0 || count < 2)
	{
		*str = base[(int)n];
		return (str);
	}
	*str = base[(long)n % size];
	p_float(n - (int)n, base, str + 1, count - 1);
	return (str);
}

char	*float_tostr_base(double n, const char *base, t_ui maxn)
{
	char	*num_int;
	char	*num_float;
	double	tmp;

	num_int = int_tostr_base((long)n, base);
	if (!num_int)
		return (NULL);
	if (maxn < 1)
		return (num_int);
	num_float = malloc((maxn + 2) * sizeof(char));
	if (!num_float)
		return (NULL);
	*num_float = FDOT;
	ft_memset(num_float + 1, ZERRO_CH, maxn);
	num_float[maxn + 1] = '\0';
	tmp = n - (long)n;
	if (tmp < 0)
		tmp *= -1;
	p_float(tmp, base, num_float + 1, maxn);
	return (ft_strjoinfree(num_int, num_float, 2));
}

t_data	*float_tostr(double n, const char *spec, const char *base, t_ui m)
{
	const char	*tmp;

	tmp = spec;
	++tmp;
	return (t_datacrt(float_tostr_base(n, base, m), 0));
}
