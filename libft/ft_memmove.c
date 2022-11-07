/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:25:26 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/06 21:17:05 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*chdst;
	char	*chsrc;

	if (dst == 0 && src == 0)
		return (dst);
	chdst = (char *) dst;
	chsrc = (char *) src;
	i = -1;
	if (src < dst)
	{
		while (++i < len)
			chdst[len - 1 - i] = chsrc[len - 1 - i];
	}
	else
	{
		while (++i < len)
			chdst[i] = chsrc[i];
	}
	return (dst);
}
