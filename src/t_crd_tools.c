/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_crd._tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:31:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/12 10:33:30 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

t_crd	*crt_crd(int x, int y, int xf, int yf)
{
	t_crd	*tmp;

	tmp = malloc(sizeof(t_crd));
	if (!tmp)
		return (NULL);
	tmp->x = (float)x;
	tmp->y = (float)y;
	tmp->xf = (float)xf;
	tmp->yf = (float)yf;
	return (tmp);
}

void    scale_crd(t_crd *crd, int scale)
{
	if (!crd)
		return ;
	crd->x *= (float)scale;
	crd->y *= (float)scale;
	crd->xf *= (float)scale;
	crd->yf *= (float)scale;
}

void	setcrd_xy(t_crd *crd, int x, int y, t_uchr i)
{
    if (!crd)
		return ;
	if (i)
	{
		crd->xf = (float)x;
		crd->yf = (float)y;
		return ;
	}
	crd->x = (float)x;
	crd->y = (float)y;
}