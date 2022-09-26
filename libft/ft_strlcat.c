/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:38:55 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/26 15:45:32 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_siz;

	d_siz = ft_strlen(dst);
	i = 0;
	if (size < d_siz)
		return (ft_strlen(src) + size);
	while ((i + d_siz) + 1 < size && src[i] != 0)
	{
		dst[i + d_siz] = src[i];
		i++;
	}
	dst[i + d_siz] = 0;
	return (d_siz + ft_strlen(src));
}
