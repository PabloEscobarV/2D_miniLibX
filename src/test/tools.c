/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:02:20 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/04 10:19:19 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	*freedub(void **ptr)
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

void	*freetriple(void ***ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			free(ptr[i][j]);
			++j;
		}
		free(ptr[i]);
		++i;
	}
	free(ptr);
	return (NULL);
}
