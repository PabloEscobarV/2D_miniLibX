/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinttostr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:48:44 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/12 13:55:55 by polenyc          ###   ########.fr       */
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
	t_mod	*mod;
	t_data	*num;
	char	*tmp;

	mod = setmod(spec, MOD, SPEC);
	if (!mod)
		return (NULL);
	num = t_datacrt(uint_tostr_base(n, base), 0);
	if (!num)
		return (NULL);
	num->str = intnum_mod(mod, num, 0, '0');
	if (!num->str)
		return (NULL);
	tmp = modnstr_crt(mod, num->str);
	if (!tmp)
		return (NULL);
	if (mod->flags[INDENT] == MOD[INDENT])
		return (retres_fin(mod, num, num->str, tmp));
	return (retres_fin(mod, num, tmp, num->str));
}
