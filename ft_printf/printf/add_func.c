/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:14:28 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/12 14:41:29 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

const char	*findstart(const char *spc)
{
	while (*spc != DEV)
		--spc;
	return (spc + 1);
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
	free(ch_orig);
}
