/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 01:14:26 by jremarqu          #+#    #+#             */
/*   Updated: 2019/12/05 01:21:07 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# define SIZEX 2000
# define SIZEY 1500
# define DP map[0][0]

typedef struct		s_point
{
	void			*mlx_ptr;
	void			*win_ptr;
	float			x;
	float			y;
	float			z;
	int				is_last;
	int				color;
	int				zoom;
	int				z_zoom;
	int				shift_x;
	int				shift_y;
	float			angle;
	int				isometric;
	int				size_win_x;
	int				size_win_y;

}					t_point;

void				ft_bad_mas(t_point **map);
void				ft_bad(char *line, t_point **map);
int					ft_wordnbr(char *line, char c);
void				zoom(t_point *start, t_point *end, t_point *settings);
void				parametrs(t_point *start, t_point *finish,\
							t_point *settings);
t_point				**ft_get_map(char *name_f);
void				isometric(t_point *dot, double angle);
void				zoom(t_point *start, t_point *end, t_point *settings);
void				parametrs(t_point *start, t_point *finish,\
							t_point *settings);
void				draw(t_point **map);
void				brasenhem(t_point start, t_point finish, t_point *settings);
void				parametrs(t_point *start, t_point *finish,\
							t_point *settings);
int					deal_key(int key, t_point **map);
void				ft_error(int err);
#endif
