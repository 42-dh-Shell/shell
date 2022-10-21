/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:57:50 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/21 14:47:57 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_PRINTF_H
# define ERROR_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_pack
{
	va_list	ap;
	int		minus;
	int		plus;
	int		zero;
	int		hash;
	int		space;
	int		prec;
	int		result_length;
	int		str_idx;
	int		width;
	int		is_zero;
}	t_pack;

int		apply_all(t_pack *pack, const char *str);
int		eval_all(t_pack *pack, const char *str);
int		ft_isflag(char c);
int		error_printf(const char *str, ...);
void	ft_putstr(char *s);
void	handle_sign(t_pack *pack, int nb);
int		digit_length(int n);
int		llnumb_hexlen(unsigned long nb);
void	pack_clear(t_pack *pack);
void	print_addr(t_pack *pack);
void	print_char(t_pack *pack);
void	print_decimal(t_pack *pack);
void	print_str(t_pack *pack);
void	print_lowerhex(t_pack *pack);
void	print_upperhex(t_pack *pack);
void	print_unsigned(t_pack *pack);
void	ul_to_hexp(t_pack *pack, unsigned long nb, void (*f)(t_pack *, char *));
void	write_update(t_pack *pack, char *arg);
void	ft_putnbr_fd(int n, int fd);
void	update_w_down(t_pack *pack, char *arg);
void	onlynbr_print(int n, t_pack *pack, void (*f)(t_pack *, char *));
int		udigit_length(unsigned int n);
char	*ui_to_lhexstr(t_pack *pack, unsigned int nb, int lower);
int		num_hexlen(unsigned int nb);
void	handle_hash(t_pack *pack, int lower, unsigned int nb);
void	ui_to_hexp(t_pack *pack, unsigned int nb, void (*f)(t_pack *, char *));
void	ui_to_uphp(t_pack *pack, unsigned int nb, void (*f)(t_pack *, char *));
void	handle_ptr(t_pack *pack);
int		digit_length2(int n);
int		print_iszero(t_pack *pack);

#endif
