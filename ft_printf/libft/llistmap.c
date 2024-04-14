/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llistmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:00:53 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/02 22:09:36 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_llist	*llistmap(t_llist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_llist	*list;
	t_llist	*tmp;

	if (!f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		tmp = llistnewnode(f(lst->data));
		if (!tmp || !tmp->data)
		{
			free(tmp);
			llistclear(&list, del);
			return (NULL);
		}
		llistadd_back(&list, tmp);
		lst = lst->next;
	}
	return (list);
}
