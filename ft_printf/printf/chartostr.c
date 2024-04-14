/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:40:57 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/20 13:27:10 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

t_data	*chartostr(const char ch, const char *spec)
{
	t_data		*data;
	const char	*tmp;

	tmp = spec;
	++tmp;
	data = t_datacrt(emptystr(ch), 0);
	if (!ch)
		++data->countzerro;
	return (data);
}
