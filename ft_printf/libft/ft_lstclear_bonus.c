/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:16:32 by polenyc           #+#    #+#             */
/*   Updated: 2024/03/06 22:45:35 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del || !(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	if (!lst || !del || !(*lst))
// 		return ;
// 	ft_lstclear(&((*lst)->next), del);
// 	del((*lst)->content);
// 	free(*lst);
// 	*lst = NULL;
// }
