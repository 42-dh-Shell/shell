/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:03:18 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/11 02:04:34 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size_of)
{
	void	*p;

	p = malloc(size_of);
	if (p == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(p, 0, size_of);
	return (p);
}
