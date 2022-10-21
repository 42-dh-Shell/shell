/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:07:42 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/20 19:14:03 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	free_all(t_pack *pack)
{
	va_end(pack -> ap);
	free(pack);
}

static void	cycle_update(t_pack *pack, int *i_p, int *len_p)
{
	(*i_p) += pack -> str_idx;
	(*len_p) += pack -> result_length;
	pack_clear(pack);
}

int	error_printf(const char *str, ...)
{
	t_pack	*pack;
	int		i;
	int		len;

	i = 0;
	len = 0;
	pack = (t_pack *)malloc(sizeof(t_pack));
	if (pack == NULL)
		return (-1);
	va_start(pack -> ap, str);
	pack_clear(pack);
	while (str[i])
	{
		if (str[i] == '%')
		{
			eval_all(pack, &str[i]);
			apply_all(pack, &str[i]);
			cycle_update(pack, &i, &len);
		}
		else
			len += write(1, &str[i++], 1);
	}
	free_all(pack);
	return (len);
}
