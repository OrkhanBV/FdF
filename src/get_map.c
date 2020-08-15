/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:27:24 by ccred             #+#    #+#             */
/*   Updated: 2019/12/05 01:06:11 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_point		**ft_get_memory(int widht, int height)
{
	t_point		**new;

	new = (t_point**)malloc(sizeof(t_point*) * (height + 1));
	while (height > 0)
	{
		new[height - 1] = (t_point*)malloc(sizeof(t_point) * (widht + 1));
		height--;
	}
	return (new);
}

int			ft_get_dots(char *line, t_point **map, int y)
{
	int		x;
	char	**line_of_dots;

	x = 0;
	line_of_dots = ft_strsplit(line, ' ');
	while (line_of_dots[x])
	{
		map[y][x].x = x;
		map[y][x].y = y;
		map[y][x].z = ft_atoi(line_of_dots[x]);
		map[y][x].is_last = 0;
		free(line_of_dots[x++]);
	}
	map[y][--x].is_last = 1;
	free(line_of_dots);
	free(line);
	return (x);
}

void		valid_map(char *str, t_point **map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '-' || (str[i] > 47 && str[i] < 58)))
			ft_bad(str, map);
		if (str[i] == '-' && !(str[i + 1] > 48 && str[i + 1] < 58))
			ft_bad(str, map);
		if ((str[i] > 48 && str[i] < 58) && str[i + 1] == '-')
			ft_bad(str, map);
		i++;
	}
}

void		check(int *y, int *x, int fd, t_point **map)
{
	char	*line;
	int		counter;
	int		a;

	counter = 0;
	while (1)
	{
		if ((a = get_next_line(fd, &line)))
		{
			valid_map(line, map);
			(*y)++;
			counter = (*x);
			*x = ft_wordnbr(line, ' ');
			if (counter != (*x) && counter != 0)
				ft_bad(line, map);
			free(line);
		}
		else if ((a == 0 && (*y) == 0) || counter < 2)
			ft_bad(line, map);
		else if (a == 0)
			break ;
	}
	free(line);
}

t_point		**ft_get_map(char *name_f)
{
	int			fd;
	int			x;
	int			y;
	char		*line;
	t_point		**map;

	map = NULL;
	if ((fd = open(name_f, O_RDONLY)) < 0)
		ft_error(1);
	y = 0;
	x = 0;
	check(&y, &x, fd, map);
	close(fd);
	map = ft_get_memory(x, y);
	fd = open(name_f, O_RDONLY);
	y = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		ft_get_dots(line, map, y);
		y++;
	}
	free(line);
	map[y] = NULL;
	close(fd);
	return (map);
}
