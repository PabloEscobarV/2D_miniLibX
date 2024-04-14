/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllistadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:15:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 15:07:04 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dllist	*dllistadd_back(t_dllist **dllst, t_dllist *newnode)
{
	if (!newnode)
		return (NULL);
	if (!(*dllst))
	{
		*dllst = newnode;
		return (newnode);
	}
	if ((*dllst)->previous)
	{
		newnode->previous = (*dllst)->previous;
		(*dllst)->previous->next = newnode;
	}
	else
	{
		newnode->previous = *dllst;
		(*dllst)->next = newnode;
	}
	(*dllst)->previous = newnode;
	return (newnode);
}
