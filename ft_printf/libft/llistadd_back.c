/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llistadd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:30:32 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/22 14:53:48 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_llist	*llistadd_back(t_llist **llst, t_llist *newnode)
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
	if (tmp->previous)
	{
		while (tmp->previous->next)
			tmp = tmp->previous;
		newnode->previous = tmp->previous;
		tmp->previous->next = newnode;
	}
	else
	{
		newnode->previous = tmp;
		tmp->next = newnode;
	}
	tmp->previous = newnode;
	return (newnode);
}
