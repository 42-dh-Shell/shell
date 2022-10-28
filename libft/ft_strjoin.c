/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:00:01 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/07 16:53:10 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*result;
	int		idx;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc (sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (0);
	idx = 0;
	while (s1[idx] != 0)
	{
		result[idx] = s1[idx];
		idx++;
	}
	idx = 0;
	while (s2[idx] != 0)
	{
		result[idx + s1_len] = s2[idx];
		idx++;
	}
	result[idx + s1_len] = 0;
	return (result);
}
