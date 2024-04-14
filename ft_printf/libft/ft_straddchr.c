/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:45:50 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/23 13:58:50 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_straddchr(char *dest, char ch)
{
	char	*tmp;
	char	*res;
	int		size;

	size = ft_strlen(dest) + 2;
	if (!ch)
		--size;
	tmp = malloc(size * sizeof(char));
	if (!tmp)
		return (NULL);
	res = tmp;
	while (*dest)
	{
		*tmp = *dest;
		++dest;
		++tmp;
	}
	*tmp = ch;
	if (ch)
		*(tmp + 1) = '\0';
	return (res);
}

char	*ft_straddchrfree(char *dest, char ch)
{
	char	*tmp;

	tmp = ft_straddchr(dest, ch);
	free(dest);
	return (tmp);
}
