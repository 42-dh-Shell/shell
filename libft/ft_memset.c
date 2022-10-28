/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:33:32 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/06 15:29:43 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ch;
	size_t	idx;

	ch = (char *) b;
	idx = 0;
	while (idx < len)
		ch[idx++] = (unsigned char) c;
	return (b);
}
