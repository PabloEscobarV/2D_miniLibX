/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllistnewnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:17:41 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 16:53:37 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dllist	*dllistnewnode(int pid, void *data)
{
	t_dllist	*tmp;

	tmp = malloc(sizeof(t_dllist));
	if (!tmp)
		return (NULL);
	tmp->pid = pid;
	tmp->data = data;
	tmp->next = NULL;
	tmp->previous = NULL;
	return (tmp);
}
