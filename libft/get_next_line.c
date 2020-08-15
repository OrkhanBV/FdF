/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccred <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:52:06 by ccred             #+#    #+#             */
/*   Updated: 2019/12/05 13:24:18 by ccred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arr	*create_t_arr(const int fd)
{
	t_arr	*new;

	new = (t_arr*)malloc(sizeof(t_arr));
	if (!new)
		return (0);
	new->fd = fd;
	new->residue = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

char	*cheak_residue(char **p_n, char *residue)
{
	char	*str;

	if ((*p_n = ft_strchr(residue, '\n')) != NULL)
	{
		str = ft_strsub(residue, 0, *p_n - residue);
		ft_strcpy(residue, ++(*p_n));
	}
	else
	{
		str = ft_strnew(ft_strlen(residue) + 1);
		ft_strcat(str, residue);
		ft_strclr(residue);
	}
	return (str);
}

int		get_line(const int fd, char **line, char *residue)
{
	char	buf[BUFF_SIZE + 1];
	char	*p_n;
	char	*tmp;
	int		read_byte;

	p_n = NULL;
	read_byte = 1;
	*line = cheak_residue(&p_n, residue);
	while (!p_n && ((read_byte = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[read_byte] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(residue, ++p_n);
			ft_strclr(--p_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || read_byte < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(residue) || read_byte) ? 1 : 0);
}

int		get_next_line(const int fd, char **line)
{
	static t_arr	*new;
	t_arr			*tmp;
	int				result;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!new)
		new = create_t_arr(fd);
	tmp = new;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = create_t_arr(fd);
		tmp = tmp->next;
	}
	result = get_line(fd, line, tmp->residue);
	return (result);
}
