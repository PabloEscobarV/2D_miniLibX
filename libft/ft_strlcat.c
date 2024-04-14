/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:58:29 by polenyc           #+#    #+#             */
/*   Updated: 2023/11/19 22:17:03 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			dest_size;
	size_t			src_size;
	size_t			left_size;
	unsigned int	i;

	dest_size = 0;
	src_size = 0;
	while (dest[dest_size] != '\0' && dest_size < size)
		dest_size++;
	while (src[src_size] != '\0')
		src_size++;
	if (dest_size >= size)
		return (size + src_size);
	left_size = size - dest_size - 1;
	i = 0;
	while (src[i] != '\0' && i < left_size)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest_size + src_size);
}
