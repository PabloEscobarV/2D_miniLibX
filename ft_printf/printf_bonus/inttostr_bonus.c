/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttostr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:41:52 by polenyc           #+#    #+#             */
/*   Updated: 2024/02/09 20:56:34 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
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

char	*modnstr_crt(t_mod *mod, char *str)
{
	char	ch;
	char	*tmp;
	int		size;

	size = ft_strlen(str);
	ch = ' ';
	if (mod->flags[INDENT] != MOD[INDENT] && mod->flags[ZERO] == MOD[ZERO])
		ch = '0';
	tmp = modstr_crt(mod, size, ch);
	return (tmp);
}

int	setsign(t_mod *mod, t_data *num)
{
	int	signe;

	signe = 0;
	if (*(num->str) == MINUS)
		return (++signe);
	if (!mod->flags[SIGN] && !mod->flags[SPACE])
		return (signe);
	if (mod->flags[SIGN])
	{
		num->str = ft_strjoinfree(emptystr(mod->flags[SIGN]), num->str, 2);
		return (++signe);
	}
	num->str = ft_strjoinfree(emptystr(mod->flags[SPACE]), num->str, 2);
	return (++signe);
}

char	*intnum_mod(t_mod *mod, t_data *data, int signe, char ch)
{
	int		size;
	char	*tmp;

	if (!mod->flags[PREC])
		return (data->str);
	mod->flags[ZERO] = '\0';
	size = ft_strlen(data->str);
	if (size - signe >= mod->precision)
		return (data->str);
	if (signe)
		--size;
	tmp = ft_calloc(mod->precision - size + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	ft_memset(tmp, ch, mod->precision - size);
	if (signe)
		swap(tmp, data->str);
	return (ft_strjoinfree(tmp, data->str, 2));
}

t_data	*int_tostr(long n, const char *spec, const char *base)
{
	t_mod	*mod;
	t_data	*num;
	char	*tmp;
	char	*num_orig;

	num = t_datacrt(int_tostr_base(n, base), 0);
	if (!num)
		return (NULL);
	mod = setmod(spec, MOD, SPEC);
	if (!mod)
		return (NULL);
	num->str = intnum_mod(mod, num, setsign(mod, num), '0');
	if (!num->str)
		return (NULL);
	num_orig = ft_strdup(num->str);
	tmp = modnstr_crt(mod, num->str);
	if (!tmp)
		return (NULL);
	if (!ft_isdigit(*num_orig))
		swap_sign(mod, tmp, num->str, num_orig);
	free(num_orig);
	if (mod->flags[INDENT] == MOD[INDENT])
		return (retres_fin(mod, num, num->str, tmp));
	return (retres_fin(mod, num, tmp, num->str));
}
