/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llistclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:46:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/22 14:52:03 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*llistclear(t_llist **llst, void (*del)(void *d))
{
	if (!(*llst))
		return (NULL);
	while ((*llst)->previous && (*llst)->previous->next)
		*llst = (*llst)->previous;
	while ((*llst)->next)
	{
		*llst = (*llst)->next;
		del((*llst)->previous->data);
		free((*llst)->previous);
		(*llst)->previous = NULL;
	}
	del((*llst)->data);
	free(*llst);
	return (NULL);
}
