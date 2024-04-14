/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llistsize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:31:22 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/22 14:54:21 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	llistsize(t_llist *llst)
{
	int			size;

	if (!llst)
		return (0);
	size = 0;
	while (llst->previous && llst->previous->next)
		llst = llst->previous;
	while (llst)
	{
		llst = llst->next;
		++size;
	}
	return (size);
}
