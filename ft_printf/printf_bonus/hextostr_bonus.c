/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextostr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:02:30 by polenyc           #+#    #+#             */
/*   Updated: 2024/02/09 20:56:14 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
#include <stdlib.h>
#include <stdio.h>

char	*hexint_mod(t_mod *mod, char *str, const char *base, const char *p_h)
{
	if (!mod->flags[HEX])
		return (str);
	if (!ft_atoi_base(str, base))
		return (str);
	return (ft_strjoinfree((char *)p_h, str, 1));
}

void	swap_hex(t_mod *mod, char *str, char *num, char *ch_orig)
{
	char	*ch_tmp;
	int		i;

	if (!(*str) || !mod->flags[ZERO] || mod->flags[PREC] || mod->flags[INDENT])
		return ;
	ch_tmp = ch_orig;
	i = 0;
	while (!ft_isalnum(*ch_tmp))
		++ch_tmp;
	while (ft_strcmp(num + i, ch_tmp))
	{
		if (!str[i])
		{
			swap(num, num + i);
			++i;
			continue ;
		}
		swap(str + i, num + i);
		++i;
	}
}

t_data	*hex_tostr(long n, const char *spec, const char *base, char *p_h)
{
	t_mod	*mod;
	t_data	*num;
	char	*tmp;
	char	*num_orig;

	mod = setmod(spec, MOD, SPEC);
	if (!mod)
		return (NULL);
	num = t_datacrt(int_tostr_base(n, base), 0);
	if (!num)
		return (NULL);
	num->str = intnum_mod(mod, num, 0, '0');
	if (!num->str)
		return (NULL);
	num_orig = ft_strdup(num->str);
	num->str = hexint_mod(mod, num->str, base, p_h);
	tmp = modnstr_crt(mod, num->str);
	if (!tmp)
		return (NULL);
	swap_hex(mod, tmp, num->str, num_orig);
	free(num_orig);
	if (mod->flags[INDENT] == MOD[INDENT])
		return (retres_fin(mod, num, num->str, tmp));
	return (retres_fin(mod, num, tmp, num->str));
}
