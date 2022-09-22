/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:18:58 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/01 17:25:57 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	size_t			len;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	map = (char *)malloc(sizeof(char) * (len + 1));
	if (map == NULL)
		return (NULL);
	while (s[i])
	{
		map[i] = (*f)(i, s[i]);
		i++;
	}
	map[i] = 0;
	return (map);
}
