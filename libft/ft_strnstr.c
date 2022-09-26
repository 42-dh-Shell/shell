/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:34:15 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/26 15:45:32 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	while (*haystack && len-- > 0)
	{
		i = 0;
		while (*(haystack + i) == *(needle + i) && i <= len)
		{
			if (++i == n_len)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
