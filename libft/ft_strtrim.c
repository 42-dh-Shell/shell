/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:04:30 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/26 15:45:32 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	l_idx;
	char	*str;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	l_idx = ft_strlen(s1) - 1;
	while (l_idx != 0 && is_inset(s1[l_idx], set))
		l_idx--;
	if (l_idx == 0)
		return (ft_strdup(""));
	while (is_inset(s1[i], set))
		i++;
	str = (char *)malloc(sizeof(char) * (l_idx - i + 2));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s1[i], (l_idx - i + 2));
	return (str);
}
