/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:36:02 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/19 20:38:25 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*d)(void *), int n)
{
	t_dlist	*list;
	t_dlist	*tmp;

	if (!f || !d)
		return (NULL);
	list = NULL;
	while (lst)
	{
		tmp = ft_dlstnew(n, f(lst->content));
		if (!tmp || !tmp->content)
		{
			free(tmp);
			ft_dlstclear(&list, d);
			return (NULL);
		}
		ft_dlstadd_back(&list, tmp);
		lst = lst->next;
	}
	return (list);
}
