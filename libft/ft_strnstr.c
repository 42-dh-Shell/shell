/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:19:24 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/08 13:48:16 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == 0)
		return ((char *) haystack);
	i = 0;
	while (haystack[i] != 0 && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] != 0 && needle[j] != 0
				&& haystack[i + j] == needle[j] && i + j < len)
				j++;
			if (needle[j] == 0)
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (0);
}
