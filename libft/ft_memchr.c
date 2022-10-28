/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:50:42 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/07 11:04:11 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ch;
	size_t			i;

	ch = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (*ch == (unsigned char) c)
			return (ch);
		ch++;
		i++;
	}
	return (0);
}
