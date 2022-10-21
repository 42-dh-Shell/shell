/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:44:36 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/21 14:49:54 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_printf.h"

void	handle_sign(t_pack *pack, int nb)
{
	char	sign;

	sign = '+';
	if (nb < 0)
		sign = '-';
	if (pack -> plus)
		update_w_down(pack, &sign);
	else if (pack -> space)
	{
		if (sign == '+')
			update_w_down(pack, " ");
		else
			update_w_down(pack, &sign);
	}
	else
	{
		if (sign == '-')
			update_w_down(pack, &sign);
	}
}

void	handle_hash(t_pack *pack, int lower, unsigned int nb)
{
	if (pack -> hash && nb != 0)
	{
		if (lower)
		{
			update_w_down(pack, "0");
			update_w_down(pack, "x");
		}
		else
		{			
			update_w_down(pack, "0");
			update_w_down(pack, "X");
		}
	}
}

void	handle_ptr(t_pack *pack)
{
	update_w_down(pack, "0");
	update_w_down(pack, "x");
}
