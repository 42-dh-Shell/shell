/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:10:53 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/21 14:50:14 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_printf.h"

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

void	onlynbr_print(int n, t_pack *pack, void (*f)(t_pack *, char *))
{
	char	c;
	int		i;

	i = -1;
	if (n >= 0 && n <= 9)
	{
		c = n + '0';
		(*f)(pack, &c);
	}
	else
	{
		if (n == -2147483648)
		{
			while (++i < 10)
				(*f)(pack, &"2147483648"[i]);
		}
		else if (n < 0)
			onlynbr_print(n * -1, pack, f);
		else if (n >= 10)
		{
			c = n % 10 + '0';
			onlynbr_print(n / 10, pack, f);
			(*f)(pack, &c);
		}
	}
}

void	ft_putstr(char *s)
{
	int	len;

	len = ft_strlen(s);
	write(1, s, len);
}

void	ui_to_hexp(t_pack *pack, unsigned int nb, void (*f)(t_pack *, char *))
{
	if (nb >= 0 && nb <= 15)
		(*f)(pack, &"0123456789abcdef"[nb]);
	else
	{
		ui_to_hexp(pack, nb / 16, f);
		(*f)(pack, &"0123456789abcdef"[nb % 16]);
	}
}

void	ui_to_uphp(t_pack *pack, unsigned int nb, void (*f)(t_pack *, char *))
{
	if (nb >= 0 && nb <= 15)
		(*f)(pack, &"0123456789ABCDEF"[nb]);
	else
	{
		ui_to_uphp(pack, nb / 16, f);
		(*f)(pack, &"0123456789ABCDEF"[nb % 16]);
	}
}
