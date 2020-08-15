/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 01:07:32 by jremarqu          #+#    #+#             */
/*   Updated: 2019/12/05 01:25:53 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_bad_mas(t_point **map)
{
	free(map);
	ft_putstr("Use numbers between -500 and 500\n");
	exit(1);
}

void		ft_bad(char *line, t_point **map)
{
	free(line);
	free(map);
	ft_putstr("Use only numbers between -500 and 500");
	ft_putstr(" and use space between numbers, not use empty file");
	ft_putstr(" and use rectangular map\n");
	exit(1);
}

int			ft_wordnbr(char *line, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (line[i] != c && line[i] != '\0')
		j = 1;
	while (line[i] != '\0')
	{
		if (line[i] == c && line[i + 1] != c && line[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

void		ft_error(int err)
{
	if (err == 1)
		ft_putstr("Not valid file\n");
	exit(1);
}
