/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:54:23 by polenyc           #+#    #+#             */
/*   Updated: 2023/11/19 22:17:36 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		++src_len;
	if (size <= 0)
		return (src_len);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (src_len);
}
