/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_addfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:29:49 by polenyc           #+#    #+#             */
/*   Updated: 2024/01/22 15:23:10 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdlib.h>

size_t	ft_strlen_wch(const char *str, char end, const char ch)
{
	size_t	count;

	count = 0;
	while (*str != '\0' && *str != end)
	{
		if (*str == ch)
			++str;
		++count;
		++str;
	}
	return (count);
}

char	*ft_strcpy_toend(char *dest, const char *src)
{
	char	*data;

	if (!(*src))
		return (dest);
	data = dest;
	while (*dest)
		++dest;
	while (*src)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';
	return (data);
}

t_data	*str_tostr(const char *start, const char *end, const char dev)
{
	t_data	*str;
	size_t	len;

	len = 0;
	end = findstart(end);
	--end;
	while (start + len < end)
		++len;
	if (!len)
		return (t_datacrt(emptystr('\0'), 0));
	str = t_datacrt(ft_calloc(len + 1, sizeof(char)), 0);
	if (!str)
		return (NULL);
	len = -1;
	while (++len + start < end)
	{
		if (start[len] == dev)
			++start;
		str->str[len] = start[len];
	}
	str->str[len] = '\0';
	return (str);
}

t_data	*ft_strdup_wch(const char *src, char dev)
{
	t_data	*data;
	char	*ret_tmp;
	size_t	size;

	size = ft_strlen_wch(src, '\0', dev);
	data = t_datacrt(malloc((size + 1) * sizeof(char)), 0);
	if (!data)
		return (NULL);
	ret_tmp = data->str;
	while (size--)
	{
		if (*src == dev)
			++src;
		*ret_tmp = *src;
		++src;
		++ret_tmp;
	}
	*ret_tmp = '\0';
	return (data);
}

char	*strjoinfree(char *s1, char *s2, int pos)
{
	char	*data;

	data = ft_strjoin(s1, s2);
	if (pos < 0)
		return (data);
	if (pos == 0)
	{
		free((char *)s1);
		return (data);
	}
	if (pos == 1)
	{
		free((char *)s2);
		return (data);
	}
	free((char *)s1);
	free((char *)s2);
	return (data);
}
