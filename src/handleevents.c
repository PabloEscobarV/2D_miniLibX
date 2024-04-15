/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleevents.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:53:23 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/15 13:08:12 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include <X11/keysym.h>
#include <stdio.h>

int	scaling(t_mlxdata *app, int key, float scale)
{
	if (key == MOUSE_SCROLL_UP || key == ZOOM_IN)
		app->sc->scale += scale;
	if (key == MOUSE_SCROLL_DOWN || key == ZOOM_OUT)
		if (app->sc->scale > scale * 2)
			app->sc->scale -= scale;
	app->sc->xscale = (float)SIZE_X / app->sc->scale / (float)app->map->size_x;
	app->sc->yscale = (float)SIZE_Y / app->sc->scale / (float)app->map->size_y;
	clear_img(app);
	drawmap(app);
	return (1);
}

int	handle_mouse_scroll(int key, int x, int y, void *app)
{
	printf("mouse scroll event has been activates\n");
	return (scaling(app, key, 0.1));
}

int	changevenue(t_mlxdata *app, int key, int i)
{
	if (key == ZOOM_IN || key == ZOOM_OUT)
		return (scaling(app, key, 0.1));
	if (key != XK_Up && key != XK_Down && key != XK_Left && key != XK_Right)
		return (0);
	if (key == XK_Up)
		app->crd->ys -= i;
	if (key == XK_Down)
		app->crd->ys += i;
	if (key == XK_Left)
		app->crd->xs -= i;
	if (key == XK_Right)
		app->crd->xs += i;
	clear_img(app);
	drawmap(app);
	return (1);
}

int	handleevent(int key, t_mlxdata *app)
{
	if (key == XK_Escape)
		exitapp(app);
	if (changevenue(app, key, 10))
		return (0);
	return (0);
}

	// if (key != MOUSE_SCROLL_UP && key != MOUSE_SCROLL_DOWN)
	// 	return (0);