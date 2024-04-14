/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:08:45 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/22 14:12:42 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int pos)
{
	char	*data;

	data = ft_strjoin(s1, s2);
	if (pos < 0)
		return (data);
	if (pos == 0)
	{
		free((char *)s1);
		return (data);
	}
	if (pos == 1)
	{
		free((char *)s2);
		return (data);
	}
	free((char *)s1);
	free((char *)s2);
	return (data);
}
