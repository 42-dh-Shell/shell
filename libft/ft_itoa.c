/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:01:19 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/11 10:39:13 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_result_len(int n, char tmp[])
{
	int				len;
	unsigned int	num;
	int				idx;

	len = 0;
	if (n < 0)
	{
		len++;
		num = (unsigned int)(n * -1);
	}
	else
		num = (unsigned int) n;
	idx = 0;
	while (num > 0)
	{
		tmp[idx++] = (num % 10) + '0';
		num /= 10;
		len++;
	}
	return (len);
}

static void	fill_result(char *result, char tmp[], int n, int result_len)
{
	int	idx;

	idx = 0;
	if (n < 0)
	{
		result[idx++] = '-';
		result_len--;
	}
	result_len--;
	while (result_len >= 0)
	{
		result[idx] = tmp[result_len];
		idx++;
		result_len--;
	}
	result[idx] = 0;
}

char	*ft_itoa(int n)
{
	char	*result;
	int		result_len;
	char	tmp[12];

	if (n == 0)
		return (ft_strdup("0"));
	result_len = get_result_len(n, tmp);
	result = malloc (result_len + 1);
	if (!result)
		return (0);
	fill_result(result, tmp, n, result_len);
	return (result);
}
