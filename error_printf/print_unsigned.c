/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:00:28 by daegulee          #+#    #+#             */
/*   Updated: 2022/07/16 17:08:10 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_minus(t_pack *pack, unsigned int nb, int p_f);
static void	print_general(t_pack *pack, unsigned int nb, int p_f, int len);
static void	print_ger_zero(t_pack *pack, unsigned int nb, int len);

void	unbr_print(unsigned int n, t_pack *pack, void (*f)(t_pack *, char *))
{
	char	c;

	if (n >= 0 && n <= 9)
	{
		c = n + '0';
		(*f)(pack, &c);
	}
	else
	{
		c = n % 10 + '0';
		unbr_print(n / 10, pack, f);
		(*f)(pack, &c);
	}
}

void	print_unsigned(t_pack *pack)
{
	unsigned int	nb;
	int				prec_flag;
	int				len;

	nb = va_arg(pack -> ap, unsigned int);
	len = udigit_length(nb);
	prec_flag = pack -> prec - len ;
	if (pack -> is_zero && nb == 0)
	{
		print_iszero(pack);
		return ;
	}
	if (pack -> hash || pack -> space || pack -> plus)
	{
		unbr_print(nb, pack, write_update);
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

	if (p_f > 0)
	{
		while (p_f--)
			write_update(pack, "0");
		unbr_print(nb, pack, write_update);
		w_f = pack -> width - pack -> prec;
		while (w_f-- > 0)
			write_update(pack, " ");
	}
	else
	{
		unbr_print(nb, pack, update_w_down);
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
		w_f = pack -> width - pack -> prec;
		while (w_f-- > 0)
			write_update(pack, " ");
		while (p_f--)
			write_update(pack, "0");
		unbr_print(nb, pack, write_update);
	}
	else
	{
		if (pack -> zero && pack -> prec == 0)
			print_ger_zero(pack, nb, len);
		else
		{
			w_f = pack -> width - len;
			while (w_f-- > 0)
				write_update(pack, " ");
			unbr_print(nb, pack, write_update);
		}
	}
}

static void	print_ger_zero(t_pack *pack, unsigned int nb, int len)
{
	int	w_f;

	w_f = pack-> width - len;
	while (w_f-- > 0)
		write_update(pack, "0");
	unbr_print(nb, pack, write_update);
}
