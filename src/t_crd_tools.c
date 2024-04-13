/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_crd_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:31:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/13 14:44:33 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

t_crd	*crt_crd(float x, float y, float z)
{
	t_crd	*tmp;

	tmp = malloc(sizeof(t_crd));
	if (!tmp)
		return (NULL);
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	tmp->x_ = x;
	tmp->y_ = y;
	tmp->z_ = z;
	return (tmp);
}

void	scale_crd(t_crd *crd, t_scale *sc)
{
	if (!crd)
		return ;
	crd->x *= sc->xscale;
	crd->y *= sc->yscale;
	crd->x_ *= sc->xscale;
	crd->y_ *= sc->yscale;
}

t_crd	*setxys(t_mlxdata *app, t_crd *crd)
{
	crd->xs = (SIZE_X - app->map->size_x * app->sc->xscale) / (1.3);
	crd->ys = (SIZE_Y - app->map->size_y * app->sc->yscale) / (2.3);
	return (crd);
}

t_crd	*setcrd_xy(t_crd *crd, int x, int y, t_uchr i)
{
	if (i)
	{
		crd->x = (float)x;
		crd->y = (float)y;
		crd->x_ = (float)x;
		crd->y_ = (float)y + 1;
		return (crd);
	}
	crd->x = (float)x;
	crd->y = (float)y;
	crd->x_ = (float)x + 1;
	crd->y_ = (float)y;
	return (crd);
}
