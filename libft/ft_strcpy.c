/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:20:07 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/22 14:06:51 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char const *src)
{
	if (!src)
		return (dest);
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';
	return (dest);
}
