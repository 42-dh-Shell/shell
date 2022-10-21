/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:24:54 by daegulee          #+#    #+#             */
/*   Updated: 2022/07/16 17:07:18 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_all(t_pack *pack, const char *str)
{
	if (str[pack -> str_idx] == 'c')
		print_char(pack);
	else if (str[pack -> str_idx] == 's')
		print_str(pack);
	else if (str[pack -> str_idx] == 'p')
		print_addr(pack);
	else if (str[pack -> str_idx] == 'd' || str[pack -> str_idx] == 'i')
		print_decimal(pack);
	else if (str[pack -> str_idx] == 'u')
		print_unsigned(pack);
	else if (str[pack -> str_idx] == 'x')
		print_lowerhex(pack);
	else if (str[pack -> str_idx] == 'X')
		print_upperhex(pack);
	else if (str[pack -> str_idx] == '%')
		write_update(pack, "%%");
	pack -> str_idx += 1;
	return (1);
}
