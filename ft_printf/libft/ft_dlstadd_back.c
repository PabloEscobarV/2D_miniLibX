/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:23:31 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/19 20:26:24 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlist **lst, t_dlist *newnode)
{
	t_dlist	*last;

	if (!newnode)
		return ;
	newnode->next = NULL;
	if (*lst == NULL)
	{
		*lst = newnode;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = newnode;
}
