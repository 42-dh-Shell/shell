/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:30:05 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/06 21:34:19 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*chdst;
	char	*chsrc;

	if (dst == src)
		return (dst);
	i = 0;
	chdst = (char *)dst;
	chsrc = (char *)src;
	while (i < n)
	{
		chdst[i] = chsrc[i];
		i++;
	}
	return (dst);
}
