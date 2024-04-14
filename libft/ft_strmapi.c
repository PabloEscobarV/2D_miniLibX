/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:25:17 by polenyc           #+#    #+#             */
/*   Updated: 2023/11/19 22:18:41 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	size_t				size;
	char				*arr;

	if (!s || !f)
		return (NULL);
	size = ft_strlen((const char *)s);
	arr = malloc((size + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		arr[i] = f(i, s[i]);
	arr[i] = '\0';
	return (arr);
}
