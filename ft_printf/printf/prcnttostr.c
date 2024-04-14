/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prcnttostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:01:50 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/12 14:42:31 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
#include <stdlib.h>

t_data	*prcnttostr(const char *spec)
{
	return (t_datacrt(emptystr(*spec), 0));
}
