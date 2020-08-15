/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 01:11:38 by jremarqu          #+#    #+#             */
/*   Updated: 2019/12/05 01:24:59 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_basis_inicialization(t_point *map)
{
	map->size_win_x = 2000;
	map->size_win_y = 1500;
	map->isometric = 1;
	map->shift_x = map->size_win_x / 3;
	map->shift_y = map->size_win_y / 3;
	map->zoom = 20;
	map->z_zoom = 1;
	map->angle = 0.8;
}

int			ft_exit(void)
{
	exit(0);
}

int			main(int argc, char **argv)
{
	t_point		**map;

	if (argc != 2)
	{
		ft_putstr("\nusage: ./fdf file_with_map or test_maps");
		ft_putstr(" (whith only numbers between -500 and 500)\n");
		exit(1);
	}
	map = ft_get_map(argv[1]);
	map[0][0].mlx_ptr = mlx_init();
	map[0][0].win_ptr = mlx_new_window(map[0][0].mlx_ptr, SIZEX, SIZEY, "FDF");
	ft_basis_inicialization(&DP);
	draw(map);
	mlx_key_hook(map[0][0].win_ptr, deal_key, map);
	mlx_hook(DP.win_ptr, 17, 1L << 17, &ft_exit, 0);
	mlx_loop(DP.mlx_ptr);
	free(map);
	return (0);
}
