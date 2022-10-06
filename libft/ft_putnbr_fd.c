/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:10:53 by daegulee          #+#    #+#             */
/*   Updated: 2022/07/09 19:26:21 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n >= 0 && n <= 9)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	else
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else if (n < 0)
		{
			write(fd, "-", 1);
			ft_putnbr_fd(n * -1, fd);
		}
		else if (n >= 10)
		{
			c = n % 10 + '0';
			ft_putnbr_fd(n / 10, fd);
			write(fd, &c, 1);
		}
	}
}
