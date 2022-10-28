/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:38:38 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/18 11:41:36 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size)
{
	void	*result;

	result = ft_calloc (size, 1);
	if (!result)
		ft_exit("malloc error\n", 1);
	return (result);
}
