/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:28:04 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/10 14:43:08 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(void *ptr)
{
	if (!ptr)
		return (NULL);
	free(ptr);
	return (NULL);
}

void	*ft_free_d(void **ptr)
{
	void	**tmp;

	if (!ptr)
		return (NULL);
	tmp = ptr;
	while (*tmp)
	{
		free(*tmp);
		++tmp;
	}
	free(ptr);
	return (NULL);
}

void	*ft_free_t(void ***ptr)
{
	void	***tmp;
	void	**tmp_d;

	if (!ptr)
		return (NULL);
	tmp = ptr;
	while (*tmp)
	{
		tmp_d = *tmp;
		while (**tmp)
		{
			free(**tmp);
			++(*tmp);
		}
		free(tmp_d);
		++tmp;
	}
	free(ptr);
	return (NULL);
}
