/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:02:30 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/10 18:24:37 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdlib.h>

t_data	*hex_tostr(long n, const char *spec, const char *base, char *p_h)
{
	const char	*tmp;

	tmp = spec;
	tmp = (const char *)p_h;
	++tmp;
	return (t_datacrt(int_tostr_base(n, base), 0));
}
