/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:29:05 by polenyc           #+#    #+#             */
/*   Updated: 2023/11/20 19:52:44 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (dest == src)
		return (dest);
	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	if (src < dest)
	{
		while ((n--) > 0)
			dest_tmp[n] = src_tmp[n];
		return (dest);
	}
	i = -1;
	while (++i < n)
		dest_tmp[i] = src_tmp[i];
	return (dest);
}
