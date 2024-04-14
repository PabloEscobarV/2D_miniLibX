/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllistadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:15:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 14:17:04 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dllist	*dllistadd_front(t_dllist **dllst, t_dllist *newnode)
{
	if (!newnode)
		return (NULL);
	if (!(*dllst))
	{
		*dllst = newnode;
		return (newnode);
	}
	newnode->next = *dllst;
	if ((*dllst)->previous)
		newnode->previous = (*dllst)->previous;
	else
		newnode->previous = *dllst;
	(*dllst)->previous = newnode;
	*dllst = newnode;
	return (*dllst);
}
