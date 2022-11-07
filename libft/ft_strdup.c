/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:57:20 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/07 14:22:41 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*result;
	int		size;

	size = ft_strlen(s1);
	result = malloc (sizeof(char) * size + 1);
	if (!result)
		return (0);
	i = 0;
	while (i < size)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
