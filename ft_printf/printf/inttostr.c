/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:41:52 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/10 18:20:28 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdlib.h>
#include <limits.h>

char	*int_tostr_base(long n, const char *base)
{
	char	*str;
	t_ui	base_s;
	t_ul	tmp;

	str = crtnumstr(n, base);
	if (!str)
		return (NULL);
	base_s = ft_strlen(base);
	if (n < 0)
	{
		if (n == LONG_MIN)
			tmp = 1 + (t_ul)(-1 * (n + 1));
		tmp = -1 * n;
		*str = '-';
		p_rec(tmp, base, str + 1, base_s);
		return (str);
	}
	p_rec(n, base, str, base_s);
	return (str);
}

t_data	*int_tostr(long n, const char *spec, const char *base)
{
	const char	*tmp;

	tmp = spec;
	++tmp;
	return (t_datacrt(int_tostr_base(n, base), 0));
}
