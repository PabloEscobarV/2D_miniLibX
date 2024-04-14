/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:26:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/19 20:27:48 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_dlstadd_front(t_dlist **lst, t_dlist *newnode)
{
	if (!newnode)
		return ;
	newnode->next = *lst;
	*lst = newnode;
}
