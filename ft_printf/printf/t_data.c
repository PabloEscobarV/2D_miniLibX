/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:57:38 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/12 13:54:23 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
#include <stdlib.h>

void	delt_data(void *ptr)
{
	free(((t_data *)ptr)->str);
	free((t_data *)ptr);
}

t_data	*t_datacrt(char *str, int countzerro)
{
	t_data	*data;

	if (!str)
		return (NULL);
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->str = str;
	data->countzerro = countzerro;
	return (data);
}
