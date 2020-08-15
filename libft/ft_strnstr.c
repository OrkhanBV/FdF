/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 22:16:27 by jremarqu          #+#    #+#             */
/*   Updated: 2019/12/05 13:33:47 by ccred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t n;

	n = ft_strlen(s2);
	i = 0;
	if (!s2 && len == 0)
		return ((char*)s1);
	if (s2[0] == '\0' || s1 == s2)
		return ((char*)s1);
	while (s1[i] != '\0' && i <= len)
	{
		if (((n + i) <= len) && (!(ft_memcmp(s1 + i, s2, n))))
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
