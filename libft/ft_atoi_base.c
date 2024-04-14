/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:15:25 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/03 14:21:40 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*getprefix(const char *num, int size)
{
	if (size != 16 && size != 8)
		return (num);
	while (*num == '0')
		++num;
	if (*num == 'X' || *num == 'x')
		return (num + 1);
	return (num);
}

int	setreg(const char *base, int size_b)
{
	if (size_b > 10 && base[10] >= 'A' && base[10] <= 'Z')
		return (32);
	if (size_b > 10 && base[10] >= 'a' && base[10] <= 'z')
		return (-32);
	return (0);
}

int	number(const char *base, int reg, char ch)
{
	int		num;

	num = 0;
	while (base[num] != ch && (base[num] + reg) != ch)
		++num;
	return (num);
}

long	getnum(const char *num, const char *base, int size, int reg)
{
	long	res;

	res = 0;
	while (*num && (ft_strchr(base, *num) || ft_strchr(base, *num - reg)))
	{
		res = res * size + number(base, reg, *num);
		++num;
	}
	return (res);
}

long	ft_atoi_base(const char *num, const char *base)
{
	int		sign;
	int		size_b;
	int		reg;

	sign = 1;
	if (!num || !base)
		return (0);
	size_b = ft_strlen(base);
	while (ft_isspace(*num))
		++num;
	if (*num == '-' || *num == '+')
	{
		if (*num == '-')
			sign = -1;
		++num;
	}
	reg = setreg(base, size_b);
	num = getprefix(num, size_b);
	return (getnum(num, base, size_b, reg) * (long)sign);
}
