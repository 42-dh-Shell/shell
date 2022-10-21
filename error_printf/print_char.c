/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:02:14 by daegulee          #+#    #+#             */
/*   Updated: 2022/07/16 17:07:54 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_minus(t_pack *pack, char *arg)
{
	update_w_down(pack, arg);
	while ((pack -> width)-- > 0)
		write_update(pack, " ");
}

static void	print_general(t_pack *pack, char *arg)
{
	int	w_f;

	w_f = pack -> width - 1;
	while (w_f-- > 0)
		write_update(pack, " ");
	update_w_down(pack, arg);
}

void	print_char(t_pack *pack)
{
	char	arg;

	arg = va_arg(pack -> ap, int);
	if (pack -> plus || pack -> zero || pack -> space || pack -> hash
		|| pack -> prec)
	{	
		write_update(pack, &arg);
		return ;
	}
	if (pack -> minus)
		print_minus(pack, &arg);
	else
		print_general(pack, &arg);
}
