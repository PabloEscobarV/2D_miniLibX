/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fun_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:14:28 by polenyc           #+#    #+#             */
/*   Updated: 2024/02/09 20:55:29 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
#include <stdio.h>

const char	*findstart(const char *spc)
{
	--spc;
	while (*spc != DEV)
		--spc;
	return (spc + 1);
}

t_data	*retres_fin(t_mod *mod, t_data *data, char *s1, char *s2)
{
	modfree(mod);
	data->str = ft_strjoinfree(s1, s2, 2);
	return (data);
}

char	*emptystr(char ch)
{
	char	*tmp;
	int		size;

	size = 1;
	if (ch != '\0')
		size += 1;
	tmp = ft_calloc(size, sizeof(char));
	if (!tmp)
		return (NULL);
	*tmp = ch;
	return (tmp);
}

void	swap(char *s1, char *s2)
{
	char	tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	swap_sign(t_mod *mod, char *str, char *num, char *ch_orig)
{
	char	tmp;
	char	*ch_tmp;

	if (!(*str) || !mod->flags[ZERO] || mod->flags[PREC] || mod->flags[INDENT])
		return ;
	ch_tmp = ch_orig;
	while (!ft_isalnum(*ch_tmp))
		++ch_tmp;
	while (ft_strcmp(num, ch_tmp))
	{
		tmp = *str;
		*str = *num;
		*num = tmp;
		++str;
		++num;
	}
}
