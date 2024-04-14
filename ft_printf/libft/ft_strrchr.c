/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:44:43 by polenyc           #+#    #+#             */
/*   Updated: 2023/11/21 14:35:06 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *str, int c)
{
	char			*tmp;
	unsigned char	ch;

	ch = (unsigned char)c;
	tmp = NULL;
	while (*str != '\0')
	{
		if (ch == *str)
			tmp = (char *)str;
		++str;
	}
	if (ch == *str)
		return ((char *)str);
	return (tmp);
}
