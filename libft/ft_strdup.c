/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:15:30 by polenyc           #+#    #+#             */
/*   Updated: 2023/11/22 14:11:57 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*tmp;
	int		size;

	size = 0;
	while (src[size] != '\0')
		++size;
	tmp = (char *)malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	size = 0;
	while (src[size] != '\0')
	{
		tmp[size] = src[size];
		++size;
	}
	tmp[size] = '\0';
	return (tmp);
}
