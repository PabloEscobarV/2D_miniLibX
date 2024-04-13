/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_crd_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:31:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/13 13:38:12 by blackrider       ###   ########.fr       */
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

void	scale_crd(t_crd *crd, t_scale *sc)
{
	if (!crd)
		return ;
	crd->x *= sc->xscale;
	crd->y *= sc->yscale;
	crd->xf *= sc->xscale;
	crd->yf *= sc->yscale;
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
		crd->xf = (float)x;
		crd->yf = (float)y + 1;
		return (crd);
	}
	crd->x = (float)x;
	crd->y = (float)y;
	crd->xf = (float)x + 1;
	crd->yf = (float)y;
	return (crd);
}
