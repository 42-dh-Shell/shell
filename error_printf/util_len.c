/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:25:24 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/21 14:52:00 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_printf.h"

int	digit_length2(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = n * -1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	digit_length(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (0);
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = n * -1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	udigit_length(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	llnumb_hexlen(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		len++;
		nb /= 16;
	}
	return (len);
}
