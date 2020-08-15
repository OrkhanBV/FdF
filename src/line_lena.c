/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_Lena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 01:10:38 by jremarqu          #+#    #+#             */
/*   Updated: 2019/12/05 01:10:43 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

float		ft_mod(float nb)
{
	if (nb < 0)
		nb = nb * (-1);
	else
		nb = nb * 1;
	return (nb);
}

float		ft_max(float x, float y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

int			ft_color(t_point a, t_point b)
{
	int color;

	color = 0x00ffff;
	if (b.z != 0 || a.z != 0)
		color = 0xff0000;
	if (b.z != a.z)
		color = 0x800000;
	return (color);
}

void		brasenhem(t_point start, t_point finish, t_point *settings)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	parametrs(&start, &finish, settings);
	step_x = finish.x - start.x;
	step_y = finish.y - start.y;
	max = ft_max(ft_mod(step_x), ft_mod(step_y));
	step_x /= max;
	step_y /= max;
	color = ft_color(start, finish);
	while (((int)(finish.x - start.x)) || ((int)(finish.y - start.y)))
	{
		mlx_pixel_put(settings->mlx_ptr, settings->win_ptr, \
			start.x, start.y, color);
		start.x += step_x;
		start.y += step_y;
		if (start.x > settings->size_win_x || start.y > settings->size_win_y \
			|| start.x < 0 || start.y < 0)
			break ;
	}
}

void		draw(t_point **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (1)
		{
			if (map[y + 1])
				brasenhem(map[y][x], map[y + 1][x], &DP);
			if (map[y][x].is_last != 1)
				brasenhem(map[y][x], map[y][x + 1], &DP);
			else
				break ;
			x++;
		}
		y++;
	}
}
