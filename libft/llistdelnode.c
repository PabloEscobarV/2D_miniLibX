/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llistdelnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:46:51 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/22 14:51:51 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_llist	*llistdelfirst(t_llist **ll, void (*del)(void *))
{
	t_llist	*tmp;

	if (!(*ll))
		return (NULL);
	tmp = (*ll)->next;
	if (tmp != (*ll)->previous)
		tmp->previous = (*ll)->previous;
	else
		tmp->previous = NULL;
	del((*ll)->data);
	free(*ll);
	*ll = tmp;
	return (*ll);
}

t_llist	*llistdellast(t_llist **ll, void (*del)(void *))
{
	t_llist	*tmp;

	if (!(*ll))
		return (NULL);
	tmp = (*ll)->previous;
	if (tmp)
		tmp->next = NULL;
	del((*ll)->data);
	free(*ll);
	*ll = tmp;
	return (*ll);
}

t_llist	*llistdelnode(t_llist **ll, void (*del)(void *))
{
	t_llist	*tmp;

	if (!(*ll))
		return (NULL);
	if (*ll == (*ll)->previous || (!(*ll)->next && !(*ll)->previous))
	{
		del((*ll)->data);
		free(*ll);
		*ll = NULL;
		return (*ll);
	}
	if (!(*ll)->previous->next)
		return (llistdelfirst(ll, del));
	if (!(*ll)->next)
		return (llistdellast(ll, del));
	tmp = *ll;
	tmp->previous->next = tmp->next;
	tmp->next->previous = tmp->previous;
	*ll = tmp->next;
	del((*ll)->data);
	free(*ll);
	return (*ll);
}
