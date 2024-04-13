/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:05:00 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/13 14:40:48 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"
#include <math.h>

void	rotate_x(t_crd  *crd, float alfa)
{
	float	tmp;

	tmp = crd->y;
	crd->y = crd->y * cos(alfa) - crd->z * sin(alfa);
	crd->z = tmp * sin(alfa) + crd->z * cos(alfa);
	tmp = crd->y_;
	crd->y_ = crd->y_ * cos(alfa) - crd->z_ * sin(alfa);
	crd->z_ = tmp * sin(alfa) + crd->z_ * sin(alfa);
}

void	rotate_y(t_crd  *crd, float alfa)
{
    float	tmp;

	tmp = crd->x;
	crd->x = crd->x * cos(alfa) + crd->z * sin(alfa);
	crd->z = crd->z * cos(alfa) - tmp * sin(alfa);
	tmp = crd->x_;
	crd->x_ = crd->x_ * cos(alfa) + crd->z_ * sin(alfa);
	crd->z_ = crd->z_ * cos(alfa) - tmp * sin(alfa);
}

void	rotate_z(t_crd  *crd, float alfa)
{
    float	tmp;

	tmp = crd->x;
	crd->x = crd->x * cos(alfa) - crd->y * sin(alfa);
	crd->y = tmp * sin(alfa) + crd->y * cos(alfa);
	tmp = crd->x_;
	crd->x_ = crd->x_ * cos(alfa) - crd->y_ * sin(alfa);
	crd->y_ = tmp * sin(alfa) + crd->y_ * cos(alfa);
}
