/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:59:47 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/06 21:16:22 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;

	i = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize <= dst_size)
		return (src_size + dstsize);
	while (src[i] != 0 && (dst_size + i + 1) < dstsize)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = 0;
	return (src_size + dst_size);
}
