/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:58:25 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/27 22:04:08 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	int	i;
	int	n_len;

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
