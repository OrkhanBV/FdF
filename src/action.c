/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:24:34 by ccred             #+#    #+#             */
/*   Updated: 2019/12/04 21:26:42 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_key(int key)
{
	return (key == 69 || key == 78 || key == 28 || key == 19 ||\
			key == '~' || key == '}' || key == '{' || key == '|' ||\
			key == 23 || key == 21 || key == 49 || key == 22);
}

void	do_key(int key, t_point **map)
{
	if (key == 69)
		DP.zoom += 3;
	if (key == 78)
		DP.zoom -= 3;
	if (key == 28)
		DP.z_zoom += 1;
	if (key == 19)
		DP.z_zoom -= 1;
	if (key == '~')
		DP.shift_y -= 10;
	if (key == '}')
		DP.shift_y += 10;
	if (key == '{')
		DP.shift_x -= 10;
	if (key == '|')
		DP.shift_x += 10;
	if (key == 49 || key == 23)
		DP.isometric = (DP.isometric) ? 0 : 1;
	if (key == 21)
		DP.angle += 0.05;
	if (key == 22)
		DP.angle -= 0.05;
}

int		deal_key(int key, t_point **map)
{
	if (is_key(key))
	{
		mlx_clear_window(DP.mlx_ptr, DP.win_ptr);
		do_key(key, map);
		draw(map);
	}
	if (key == '5')
	{
		mlx_destroy_window(DP.mlx_ptr, DP.win_ptr);
		free(map);
		exit(0);
	}
	return (0);
}
