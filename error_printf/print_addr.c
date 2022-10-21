/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:47:52 by daegulee          #+#    #+#             */
/*   Updated: 2022/07/16 17:07:48 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_minus(t_pack *pack, unsigned	long nb, int p_f);
static void	print_general(t_pack *pack, unsigned long nb, int p_f, int len);
static void	print_ger_zero(t_pack *pack, unsigned long nb, int len);

void	print_addr(t_pack *pack)
{
	unsigned long		nb;
	int					prec_flag;
	int					len;

	nb = va_arg(pack -> ap, unsigned long);
	len = llnumb_hexlen(nb);
	prec_flag = pack -> prec - len;
	if (pack -> plus || pack -> space)
	{
		ul_to_hexp(pack, nb, write_update);
		return ;
	}
	if (pack -> minus)
		print_minus(pack, nb, prec_flag);
	else
		print_general(pack, nb, prec_flag, len);
}

static void	print_minus(t_pack *pack, unsigned long nb, int p_f)
{
	int	w_f;

	handle_ptr(pack);
	if (p_f > 0)
	{
		while (p_f--)
			write_update(pack, "0");
		ul_to_hexp(pack, nb, write_update);
		w_f = pack -> width - pack -> prec;
		while (w_f-- > 0)
			write_update(pack, " ");
	}
	else
	{
		ul_to_hexp(pack, nb, update_w_down);
		w_f = pack -> width;
		while (w_f-- > 0)
			write_update(pack, " ");
	}
}

static void	print_general(t_pack *pack, unsigned long nb, int p_f, int len)
{
	int	w_f;

	if (p_f > 0)
	{
		w_f = pack -> width - pack -> prec - 2;
		while (w_f-- > 0)
			write_update(pack, " ");
		handle_ptr(pack);
		while (p_f--)
			write_update(pack, "0");
		ul_to_hexp(pack, nb, write_update);
	}
	else
	{
		if (pack -> zero && pack -> prec == 0)
			print_ger_zero(pack, nb, len);
		else
		{
			w_f = pack -> width - len - 2;
			while (w_f-- > 0)
				write_update(pack, " ");
			handle_ptr(pack);
			ul_to_hexp(pack, nb, write_update);
		}
	}
}

static void	print_ger_zero(t_pack *pack, unsigned long nb, int len)
{
	int	w_f;

	handle_ptr(pack);
	w_f = pack-> width - len;
	while (w_f-- > 0)
		write_update(pack, "0");
	ul_to_hexp(pack, nb, write_update);
}
