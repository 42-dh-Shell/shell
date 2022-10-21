/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:24:45 by daegulee          #+#    #+#             */
/*   Updated: 2022/07/16 17:08:07 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_minus(t_pack *pack, char *arg, int w_f, int p_f)
{
	int	i;

	i = 0;
	if (pack -> prec == 0)
	{
		w_f = pack -> width - ft_strlen(arg);
		while (p_f-- > 0)
			write_update(pack, &arg[i++]);
		while (w_f-- > 0)
			write_update(pack, " ");
	}
	else if (p_f >= 0)
	{
		while ((pack -> prec)-- > 0)
			write_update(pack, &arg[i++]);
		while (w_f-- > 0)
			write_update(pack, " ");
	}
	else
	{
		while (arg[i])
			write_update(pack, &arg[i++]);
		while (w_f-- > 0)
			write_update(pack, " ");
	}
}

static void	print_general(t_pack *pack, char *arg, int w_f, int p_f)
{
	int	i;

	i = 0;
	if (pack -> prec == 0)
	{
		w_f = pack -> width - ft_strlen(arg);
		while (w_f-- > 0)
			write_update(pack, " ");
		while (p_f-- > 0)
			write_update(pack, &arg[i++]);
	}
	if (p_f >= 0)
	{
		while (w_f-- > 0)
			write_update(pack, " ");
		while ((pack -> prec)-- > 0)
			write_update(pack, &arg[i++]);
	}
	else
	{
		while (w_f-- > 0)
			write_update(pack, " ");
		while (arg[i])
			write_update(pack, &arg[i++]);
	}
}

void	print_str(t_pack *pack)
{
	char		*s;
	int			width_flag;
	int			prec_flag;

	s = va_arg(pack -> ap, char *);
	if (s == NULL)
		s = "(null)";
	if (pack -> is_zero && print_iszero(pack))
		return ;
	if (pack -> plus || pack -> zero || pack -> space || pack -> hash)
	{
		ft_putstr(s);
		pack -> result_length += ft_strlen(s);
		return ;
	}
	prec_flag = ft_strlen(s) - pack -> prec;
	if (prec_flag >= 0)
		width_flag = pack -> width - pack -> prec;
	else
		width_flag = pack -> width - ft_strlen(s);
	if (pack -> minus)
		print_minus(pack, s, width_flag, prec_flag);
	else
		print_general(pack, s, width_flag, prec_flag);
}
