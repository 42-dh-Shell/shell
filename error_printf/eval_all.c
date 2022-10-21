/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:40:56 by daegulee          #+#    #+#             */
/*   Updated: 2022/07/16 17:07:22 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	eval_flag(t_pack *pack, const char *str)
{
	int	i;

	i = 0;
	while (ft_isflag(str[++i]))
	{
		if (str[i] == '-')
			pack -> minus = 1;
		if (str[i] == '+')
			pack -> plus = 1;
		if (str[i] == '0')
			pack -> zero = 1;
		if (str[i] == '#')
			pack -> hash = 1;
		if (str[i] == ' ')
			pack -> space = 1;
	}
	pack -> str_idx = i;
}

static	void	eval_width(t_pack *pack, const char *str)
{
	pack -> width = ft_atoi(&str[pack -> str_idx]);
	pack -> str_idx += digit_length(pack -> width);
}

static void	eval_prec(t_pack *pack, const char *str)
{
	if (str[pack -> str_idx] == '.')
	{
		pack -> str_idx += 1;
		if ('0' <= str[pack->str_idx] && str[pack->str_idx] <= '9')
		{
			pack -> prec = ft_atoi(&str[pack -> str_idx]);
			if (pack -> prec == 0)
				pack -> is_zero = 1;
			pack -> str_idx += digit_length2(pack -> prec);
		}
		else
			pack -> is_zero = 1;
	}
}

int	eval_all(t_pack *pack, const char *str)
{
	eval_flag(pack, str);
	eval_width(pack, str);
	eval_prec(pack, str);
	return (1);
}
