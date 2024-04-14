/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllistdelnode.c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:21:01 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 20:10:11 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dllist	*dllistdelfirst(t_dllist **dll, void (*del)(void *))
{
	t_dllist	*tmp;

	if (!(*dll))
		return (NULL);
	tmp = (*dll)->next;
	if (tmp != (*dll)->previous)
		tmp->previous = (*dll)->previous;
	else
		tmp->previous = NULL;
	del((*dll)->data);
	free(*dll);
	*dll = tmp;
	return (*dll);
}

t_dllist	*dllistdellast(t_dllist **dll, void (*del)(void *))
{
	t_dllist	*tmp;

	if (!(*dll))
		return (NULL);
	tmp = (*dll)->previous;
	if (tmp)
		tmp->next = NULL;
	del((*dll)->data);
	free(*dll);
	*dll = tmp;
	return (*dll);
}

t_dllist	*dllistdelnode(t_dllist **dll, void (*del)(void *))
{
	t_dllist	*tmp;

	if (!(*dll))
		return (NULL);
	if (*dll == (*dll)->previous || (!(*dll)->next && !(*dll)->previous))
	{
		del((*dll)->data);
		free(*dll);
		*dll = NULL;
		return (*dll);
	}
	if (!(*dll)->previous->next)
		return (dllistdelfirst(dll, del));
	if (!(*dll)->next)
		return (dllistdellast(dll, del));
	tmp = *dll;
	tmp->previous->next = tmp->next;
	tmp->next->previous = tmp->previous;
	*dll = tmp->next;
	del((*dll)->data);
	free(*dll);
	return (*dll);
}
