/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lowerhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:03:28 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/21 14:50:14 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_printf.h"

static void	print_minus(t_pack *pack, unsigned	int nb, int p_f);
static void	print_general(t_pack *pack, unsigned int nb, int p_f, int len);
static void	print_ger_zero(t_pack *pack, unsigned int nb, int len);

static int	sign_hlen(t_pack *pack, unsigned int nb)
{
	if (pack -> hash && nb != 0)
		return (2);
	else
		return (0);
}

void	print_lowerhex(t_pack *pack)
{
	unsigned int		nb;
	int					prec_flag;
	int					len;

	nb = va_arg(pack -> ap, unsigned int);
	len = num_hexlen(nb);
	prec_flag = pack -> prec - len;
	if (pack -> is_zero && nb == 0)
	{
		print_iszero(pack);
		return ;
	}
	if (pack -> plus || pack -> space)
	{
		ui_to_hexp(pack, nb, write_update);
		return ;
	}
	if (pack -> minus)
		print_minus(pack, nb, prec_flag);
	else
		print_general(pack, nb, prec_flag, len);
}

static void	print_minus(t_pack *pack, unsigned int nb, int p_f)
{
	int	w_f;

	handle_hash(pack, 1, nb);
	if (p_f > 0)
	{
		while (p_f--)
			write_update(pack, "0");
		ui_to_hexp(pack, nb, write_update);
		w_f = pack -> width - pack -> prec;
		while (w_f-- > 0)
			write_update(pack, " ");
	}
	else
	{
		ui_to_hexp(pack, nb, update_w_down);
		w_f = pack -> width;
		while (w_f-- > 0)
			write_update(pack, " ");
	}
}

static void	print_general(t_pack *pack, unsigned int nb, int p_f, int len)
{
	int	w_f;

	if (p_f > 0)
	{
		w_f = pack -> width - pack -> prec - sign_hlen(pack, nb);
		while (w_f-- > 0)
			write_update(pack, " ");
		handle_hash(pack, 1, nb);
		while (p_f--)
			write_update(pack, "0");
		ui_to_hexp(pack, nb, write_update);
	}
	else
	{
		if (pack -> zero && pack -> prec == 0)
			print_ger_zero(pack, nb, len);
		else
		{
			w_f = pack -> width - len - sign_hlen(pack, nb);
			while (w_f-- > 0)
				write_update(pack, " ");
			handle_hash(pack, 1, nb);
			ui_to_hexp(pack, nb, write_update);
		}
	}
}

static void	print_ger_zero(t_pack *pack, unsigned int nb, int len)
{
	int	w_f;

	handle_hash(pack, 1, nb);
	w_f = pack-> width - len;
	while (w_f-- > 0)
		write_update(pack, "0");
	ui_to_hexp(pack, nb, write_update);
}
