/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prcnttostr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:01:50 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/12 14:44:09 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
#include <stdlib.h>

t_data	*prcnttostr(const char *spec)
{
	t_data	*data;
	t_mod	*mod;
	char	*tmp;

	mod = setmod(spec, MOD, SPEC);
	if (!mod)
		return (NULL);
	data = t_datacrt(emptystr(*spec), 0);
	if (!data)
		return (NULL);
	tmp = modstr_crt(mod, ft_strlen(data->str), ' ');
	if (!tmp)
		return (NULL);
	if (mod->flags[INDENT] == MOD[INDENT])
		return (retres_fin(mod, data, data->str, tmp));
	return (retres_fin(mod, data, tmp, data->str));
}
