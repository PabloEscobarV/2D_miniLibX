/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:36:19 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/10 18:21:46 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdlib.h>

t_data	*tostr_mod(const char *str, const char *spec)
{
	const char	*tmp;

	tmp = spec;
	++tmp;
	if (!str)
		return (t_datacrt(ft_strdup("(null)"), 0));
	return (t_datacrt(ft_strdup(str), 0));
}
