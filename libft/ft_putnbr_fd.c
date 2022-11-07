/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:20:27 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/08 10:31:24 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_putnbr(long long num, int fd)
{
	char	ch;

	if (num < 10)
	{
		ch = num + '0';
		write (fd, &ch, 1);
	}
	else
	{
		ft_putnbr(num / 10, fd);
		ft_putnbr(num % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	if (n < 0)
	{
		write(fd, "-", 1);
		num = (long long) n * -1;
	}
	else
		num = (long long) n;
	ft_putnbr(num, fd);
}
