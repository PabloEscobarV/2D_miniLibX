/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllistclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:17:18 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 20:05:07 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*dllistclear(t_dllist **dllst, void (*del)(void *d))
{
	if (!(*dllst))
		return (NULL);
	while ((*dllst)->previous && (*dllst)->previous->next)
		*dllst = (*dllst)->previous;
	while ((*dllst)->next)
	{
		*dllst = (*dllst)->next;
		del((*dllst)->previous->data);
		free((*dllst)->previous);
		(*dllst)->previous = NULL;
	}
	del((*dllst)->data);
	free(*dllst);
	return (NULL);
}
