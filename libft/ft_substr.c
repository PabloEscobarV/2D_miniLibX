/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:46:33 by polenyc           #+#    #+#             */
/*   Updated: 2023/11/20 22:52:16 by polenyc          ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*tmp;

	size = ft_strlen((const char *)s);
	if (*s == '\0' || start > size)
		return (str_empty());
	size -= (size_t)start;
	if (len > size)
		len = size;
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (s[i + start] != '\0' && i < len)
	{
		tmp[i] = s[i + start];
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}
