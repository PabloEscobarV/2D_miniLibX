/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllistsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:18:02 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 14:18:49 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	dllistsize(t_dllist *dllst)
{
	int			size;

	if (!dllst)
		return (0);
	size = 0;
	while (dllst)
	{
		dllst = dllst->next;
		++size;
	}
	return (size);
}
