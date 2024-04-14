/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:29:57 by polenyc           #+#    #+#             */
/*   Updated: 2023/11/22 14:59:40 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

static char	*create_str(long int n)
{
	int		size;
	char	*tmp;

	size = 1;
	if (n < 0)
	{
		++size;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		++size;
	}
	tmp = malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[size] = '\0';
	return (tmp);
}

static char	*num_to_str(char *str, long int n)
{
	if (n < 10)
	{
		*str = n + '0';
		return (++str);
	}
	str = num_to_str(str, n / 10);
	*str = n % 10 + '0';
	*(++str) = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	num;

	num = (long int)n;
	str = create_str(num);
	if (!str)
		return (NULL);
	if (num < 0)
	{
		*str = '-';
		num *= -1;
		num_to_str(str + 1, num);
		return (str);
	}
	num_to_str(str, num);
	return (str);
}
