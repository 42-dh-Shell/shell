/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:43:55 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/08 11:20:56 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*result;
	size_t		i;

	if (size && count > ((size_t) - 1) / size)
		return (0);
	result = malloc (size * count);
	if (!result)
		return (0);
	i = 0;
	while (i < size * count)
	{
		result[i] = 0;
		i++;
	}
	return ((void *) result);
}
