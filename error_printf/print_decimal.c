/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:20:23 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/21 14:50:14 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_printf.h"

static void	print_minus(t_pack *pack, int nb, int p_f);
static void	print_general(t_pack *pack, int nb, int p_f, int len);
static void	print_ger_zero(t_pack *pack, int nb, int len);

static int	sign_dlen(t_pack *pack, int nb)
{
	if (nb == 0)
		return (0);
	if (nb > 0)
	{
		if (pack -> space || pack -> plus)
			return (1);
		else
			return (0);
	}
	else
	{
		return (1);
	}
}

void	print_decimal(t_pack *pack)
{
	int		nb;
	int		prec_flag;
	int		len;

	nb = va_arg(pack -> ap, int);
	len = digit_length2(nb);
	prec_flag = pack -> prec - len;
	if (pack -> is_zero && nb == 0)
	{
		print_iszero(pack);
		return ;
	}
	if (pack -> hash)
	{
		onlynbr_print(nb, pack, write_update);
		return ;
	}
	if (pack -> minus)
		print_minus(pack, nb, prec_flag);
	else
		print_general(pack, nb, prec_flag, len);
}		

static void	print_minus(t_pack *pack, int nb, int p_f)
{
	int	w_f;

	handle_sign(pack, nb);
	if (p_f > 0)
	{
		while (p_f--)
			write_update(pack, "0");
		onlynbr_print(nb, pack, write_update);
		w_f = pack -> width - pack -> prec;
		while (w_f-- > 0)
			write_update(pack, " ");
	}
	else
	{
		onlynbr_print(nb, pack, update_w_down);
		w_f = pack -> width;
		while (w_f-- > 0)
			write_update(pack, " ");
	}
}

static void	print_general(t_pack *pack, int nb, int p_f, int len)
{
	int	w_f;

	if (p_f > 0)
	{
		w_f = pack -> width - pack -> prec - sign_dlen(pack, nb);
		while (w_f-- > 0)
			write_update(pack, " ");
		handle_sign(pack, nb);
		while (p_f--)
			write_update(pack, "0");
		onlynbr_print(nb, pack, write_update);
	}
	else
	{
		if (pack -> zero && pack -> prec == 0)
			print_ger_zero(pack, nb, len);
		else
		{
			w_f = pack -> width - len - sign_dlen(pack, nb);
			while (w_f-- > 0)
				write_update(pack, " ");
			handle_sign(pack, nb);
			onlynbr_print(nb, pack, write_update);
		}
	}
}

static void	print_ger_zero(t_pack *pack, int nb, int len)
{
	int	w_f;

	handle_sign(pack, nb);
	w_f = pack-> width - len;
	while (w_f-- > 0)
		write_update(pack, "0");
	onlynbr_print(nb, pack, write_update);
}
