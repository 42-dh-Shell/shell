/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:10:15 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/07 17:56:13 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_delim(char ch, char const *set)
{
	int	idx;

	idx = 0;
	while (set[idx] != 0)
	{
		if (set[idx] == ch)
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		start;
	char	*result;

	start = 0;
	while (is_delim(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	if (start == end + 1)
		return (ft_strdup(""));
	while (is_delim(s1[end], set))
		end--;
	result = malloc (sizeof(char) * (end - start + 2));
	if (!result)
		return (0);
	ft_strlcpy(result, s1 + start, end - start + 2);
	return (result);
}
