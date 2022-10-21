/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_iszero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:04:33 by daegulee          #+#    #+#             */
/*   Updated: 2022/07/16 17:08:01 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_iszero(t_pack *pack)
{
	while ((pack -> width)-- > 0)
		write_update(pack, " ");
	return (1);
}
