/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_magic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 01:09:46 by jremarqu          #+#    #+#             */
/*   Updated: 2019/12/05 01:09:55 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		isometric(t_point *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

void		zoom(t_point *start, t_point *end, t_point *settings)
{
	if (settings->zoom <= 5)
		settings->zoom = 5;
	start->x *= settings->zoom;
	start->y *= settings->zoom;
	start->z *= settings->z_zoom;
	end->x *= settings->zoom;
	end->y *= settings->zoom;
	end->z *= settings->z_zoom;
}

void		parametrs(t_point *start, t_point *finish, t_point *settings)
{
	zoom(start, finish, settings);
	if (settings->isometric)
	{
		isometric(start, settings->angle);
		isometric(finish, settings->angle);
	}
	start->x += settings->shift_x;
	start->y += settings->shift_y;
	finish->x += settings->shift_x;
	finish->y += settings->shift_y;
}
