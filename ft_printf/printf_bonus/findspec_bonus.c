/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findspec_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:12:38 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/11 15:42:39 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
#include <stdlib.h>

const char	*find_mod(const char *str, const char *spec)
{
	while (*spec != *str && *spec)
		++spec;
	if (*str == *spec)
		return (str);
	return (NULL);
}

const char	*checkspec(const char *str)
{
	if (*(str - 1) == DEV && *str != DEV)
	{
		while (find_mod(str, MOD))
			++str;
		while (ft_isdigit(*str))
			++str;
		if (*str == FDOT)
			++str;
		while (ft_isdigit(*str))
			++str;
		if (find_mod(str, SPEC))
			return (str);
	}
	return (NULL);
}

const char	*find_spec(const char *str)
{
	const char	*tmp;
	int			size;

	if (!(*str))
		return (NULL);
	size = ft_strlen(str);
	++str;
	while (*str)
	{
		if (*(str - 1) == DEV && *str == DEV)
		{
			if (str + 2 >= str + size)
				return (NULL);
			str += 2;
			continue ;
		}
		tmp = checkspec(str);
		if (tmp)
			return (tmp);
		++str;
	}
	return (NULL);
}

size_t	count_spec(const char *str)
{
	const char	*s_pos;
	size_t		count;

	count = 0;
	s_pos = find_spec(str);
	while (s_pos)
	{
		++count;
		s_pos = find_spec(s_pos);
	}
	return (count);
}
