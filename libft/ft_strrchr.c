/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:09:05 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/26 15:45:32 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = len - 1;
	if (c == 0)
	{
		if (*s == 0)
			return ((char *) s);
		else
			return ((char *) &s[len]);
	}
	while (i < len)
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
