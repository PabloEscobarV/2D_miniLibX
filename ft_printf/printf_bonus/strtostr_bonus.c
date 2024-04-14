/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtostr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:36:19 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/20 14:45:51 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
#include <stdlib.h>

int	isspec(const char *s, const char *spec_o)
{
	while (*s != *spec_o && *spec_o)
		++spec_o;
	if (*s != *spec_o)
		return (0);
	return ((int)*s);
}

const char	*tostr_modret(const char *str, t_mod *mod)
{
	modfree(mod);
	return (ft_strdup(str));
}

char	*modstr_crt(t_mod *mod, int size, char ch)
{
	char	*tmp;
	int		size_r;

	if (size >= mod->size)
		return (emptystr('\0'));
	size_r = mod->size - size;
	tmp = ft_calloc(size_r + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	ft_memset(tmp, ch, size_r);
	tmp[size_r] = '\0';
	return (tmp);
}

char	*str_mod(t_mod *mod, const char *str)
{
	int		size;
	char	*tmp;

	if (!str)
	{
		if (mod->flags[PREC] && mod->precision < (int)ft_strlen(STR_NULL))
		{
			str = malloc((mod->precision + 1) * sizeof(char));
			ft_strlcpy((char *)str, STR_NULL, mod->precision + 1);
			return ((char *)str);
		}
		return (ft_strdup(STR_NULL));
	}
	if (!mod->precision)
		return (ft_strdup(str));
	size = ft_strlen(str);
	if (mod->precision >= size)
		return (ft_strdup(str));
	tmp = ft_calloc(mod->precision + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	while (mod->precision--)
		tmp[mod->precision] = str[mod->precision];
	return (tmp);
}

t_data	*tostr_mod(const char *str, const char *spec)
{
	t_mod	*mod;
	char	*str_m;
	t_data	*data;

	mod = setmod(spec, MOD, SPEC);
	if (!mod)
		return (NULL);
	if (mod->flags[PREC] && !mod->precision)
		return (extren_return(t_datacrt(emptystr('\0'), 0), mod));
	data = t_datacrt(str_mod(mod, str), 0);
	if (!data)
		return (NULL);
	str_m = modstr_crt(mod, ft_strlen(data->str), ' ');
	if (!str_m)
		return (NULL);
	if (mod->flags[INDENT] == MOD[INDENT])
		return (retres_fin(mod, data, data->str, str_m));
	return (retres_fin(mod, data, str_m, data->str));
}
