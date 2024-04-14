/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llistnewnd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:47:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/22 18:46:38 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_llist	*llistnewnode(void *data)
{
	t_llist	*tmp;

	tmp = malloc(sizeof(t_llist));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->next = NULL;
	tmp->previous = NULL;
	return (tmp);
}
