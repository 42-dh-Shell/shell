/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:13:04 by daegulee          #+#    #+#             */
/*   Updated: 2022/07/16 17:07:44 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pack_clear(t_pack *pack)
{
	pack -> minus = 0;
	pack -> plus = 0;
	pack -> zero = 0;
	pack -> hash = 0;
	pack -> space = 0;
	pack -> prec = 0;
	pack -> result_length = 0;
	pack -> str_idx = 0;
	pack -> width = 0;
	pack -> is_zero = 0;
}
