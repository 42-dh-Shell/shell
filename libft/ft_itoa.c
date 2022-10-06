/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:30:12 by daegulee          #+#    #+#             */
/*   Updated: 2022/07/09 16:01:59 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_length(int n)
{
	size_t	num;
	size_t	len;
	size_t	flag;

	if (n >= 0)
		flag = 0;
	else
		flag = 1;
	len = 0;
	if (n >= 0)
		num = n;
	else if (n == INT32_MIN)
		num = (size_t)INT32_MAX + 1;
	else
		num = n * -1;
	if (num == 0)
		return (1);
	while (num)
	{
		len++;
		num /= 10;
	}
	return (flag + len);
}

static void	fill_str(char *str, int n, const size_t n_len, int neg)
{
	size_t	i;

	i = n_len;
	if (!neg)
	{
		while (i-- != 0)
		{
			str[i] = n % 10 + '0';
			n /= 10;
		}
	}
	else
	{
		while (i-- != 1)
		{
			str[i] = (n % 10) * -1 + '0';
			n /= 10;
		}
		str[i] = '-';
	}
	str[n_len] = 0;
}

char	*ft_itoa(int n)
{
	char			*str;
	int				neg;
	const size_t	n_length = num_length(n);

	if (n >= 0)
		neg = 0;
	else
		neg = 1;
	str = (char *)malloc(sizeof(char) * (n_length + 1));
	if (str == NULL)
		return (NULL);
	fill_str(str, n, n_length, neg);
	return (str);
}
