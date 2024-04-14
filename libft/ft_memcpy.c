/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:49:35 by polenyc           #+#    #+#             */
/*   Updated: 2023/11/23 15:05:13 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (!dest && !src)
		return (dest);
	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	while ((n--) > 0)
		dest_tmp[n] = src_tmp[n];
	return (dest);
}
