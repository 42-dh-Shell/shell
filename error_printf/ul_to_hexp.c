/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ul_to_hexp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:01:02 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/21 14:50:14 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_printf.h"

void	ul_to_hexp(t_pack *pack, unsigned long nb, void (*f)(t_pack *, char *))
{
	if (nb >= 0 && nb <= 15)
		(*f)(pack, &"0123456789abcdef"[nb]);
	else
	{
		ul_to_hexp(pack, nb / 16, f);
		(*f)(pack, &"0123456789abcdef"[nb % 16]);
	}
}
