/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llistiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:59:04 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/02 22:00:41 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	llistiter(t_llist *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
}
