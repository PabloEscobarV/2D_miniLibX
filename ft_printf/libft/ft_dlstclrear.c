/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclrear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:27:56 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/19 20:43:43 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_dlstclear(t_dlist **lst, void (*del)(void*))
{
	if (!lst || !del || !(*lst))
		return ;
	ft_dlstclear(&((*lst)->next), del);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
