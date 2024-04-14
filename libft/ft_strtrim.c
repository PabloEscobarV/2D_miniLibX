/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:23:26 by polenyc           #+#    #+#             */
/*   Updated: 2023/11/22 14:17:38 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*str_empty(void)
{
	char	*tmp;

	tmp = malloc(sizeof(char));
	if (!tmp)
		return (NULL);
	*tmp = '\0';
	return (tmp);
}

static int	is_set(char const *set, char ch)
{
	while (*set != ch && *set != '\0')
		++set;
	if (*set == ch)
		return (1);
	return (0);
}

static size_t	find_set(char const *str, char const *set, size_t size)
{
	size_t	len;

	len = 0;
	while (is_set(set, str[len]) && len < size)
		++len;
	while (size > len && is_set(set, str[--size]))
		++len;
	return (len);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*tmp;
	char	*s;
	size_t	size;

	if (*str == '\0')
		return (str_empty());
	size = ft_strlen((const char *)str);
	size -= find_set(str, set, size);
	if (size < 1)
		return (str_empty());
	s = malloc((size + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (is_set(set, *str))
		++str;
	tmp = s;
	while (size-- > 0 && *str != '\0')
		*s++ = *str++;
	*s = '\0';
	return (tmp);
}
