/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:14:12 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/09 23:34:35 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	if (*nptr == '\0')
		return (0);
	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	while (ft_isdigit(*nptr))
		result = result * 10 + ((*nptr++) - '0');
	return (result * sign);
}
