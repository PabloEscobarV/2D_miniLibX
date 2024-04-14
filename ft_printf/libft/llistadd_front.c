/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llistadd_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:34:16 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/22 14:54:02 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_llist	*llistadd_front(t_llist **llst, t_llist *newnode)
{
	t_llist	*tmp;

	if (!newnode)
		return (NULL);
	if (!(*llst))
	{
		*llst = newnode;
		return (newnode);
	}
	tmp = *llst;
	while (tmp->previous && tmp->previous->next)
		tmp = tmp->previous;
	newnode->next = tmp;
	if (tmp->previous)
		newnode->previous = tmp->previous;
	else
		newnode->previous = tmp;
	tmp->previous = newnode;
	tmp = newnode;
	return (*llst);
}
