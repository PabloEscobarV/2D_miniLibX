/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:31:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/19 20:39:25 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dlist	*ft_dlstnew(int number, void *content)
{
	t_dlist	*node;

	node = malloc(sizeof(t_dlist));
	if (!node)
		return (NULL);
	node->number = number;
	node->content = content;
	node->next = NULL;
	return (node);
}
