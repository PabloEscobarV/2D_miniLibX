/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numtostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:44:26 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/10 18:08:02 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdlib.h>
#include <limits.h>

char	*p_rec(t_ul n, const char *base, char *str, t_ui size)
{
	static int	t = 1;

	if (n < size)
	{
		*str = base[n];
		return (str + 1);
	}
	str = p_rec(n / size, base, str, size);
	if (t > 0)
	{
		*str = base[n % size];
		*(str + 1) = '\0';
		t = 0;
		return (str + 1);
	}
	*str = base[n % size];
	return (str + 1);
}

t_ui	arrned_num(long n, const char *base)
{
	t_ui	size;
	t_ui	base_s;
	t_ul	tmp;

	base_s = ft_strlen(base);
	size = 1;
	tmp = n;
	if (n < 0)
	{
		if (n == LONG_MIN)
			tmp = 1 + (t_ul)(-1 * (n + 1));
		tmp = -1 * n;
		++size;
	}
	while (tmp > base_s - 1)
	{
		++size;
		tmp /= base_s;
	}
	return (size);
}

char	*crtnumstr(long n, const char *base)
{
	t_ui	size;
	char	*str;

	size = arrned_num(n, base);
	str = ft_calloc((size + 1), sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

t_ui	arrned_num_ul(t_ul n, const char *base)
{
	t_ui	size;
	t_ui	base_s;
	t_ul	tmp;

	base_s = ft_strlen(base);
	size = 1;
	tmp = n;
	while (tmp > base_s - 1)
	{
		++size;
		tmp /= base_s;
	}
	return (size);
}

char	*crtnumstr_ul(t_ul n, const char *base)
{
	t_ui	size;
	char	*str;

	size = arrned_num_ul(n, base);
	str = ft_calloc((size + 1), sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}
