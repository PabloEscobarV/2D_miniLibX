/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinttostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:48:44 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/10 18:23:41 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

char	*uint_tostr_base(t_ul n, const char *base)
{
	char	*str;
	t_ui	base_s;

	str = crtnumstr_ul(n, base);
	if (!str)
		return (NULL);
	base_s = ft_strlen(base);
	p_rec(n, base, str, base_s);
	return (str);
}

t_data	*uint_tostr(t_ul n, const char *spec, const char *base)
{
	const char	*tmp;

	tmp = spec;
	++tmp;
	return (t_datacrt(uint_tostr_base(n, base), 0));
}
