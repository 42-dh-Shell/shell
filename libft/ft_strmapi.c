/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:41:25 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/07 20:46:04 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		idx;
	char	*result;
	int		str_len;

	idx = 0;
	str_len = ft_strlen(s);
	result = malloc(sizeof(char) * (str_len + 1));
	if (!result)
		return (0);
	while (s[idx] != 0)
	{
		result[idx] = f((unsigned int)idx, s[idx]);
		idx++;
	}
	result[idx] = 0;
	return (result);
}
