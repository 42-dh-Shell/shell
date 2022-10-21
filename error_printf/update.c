/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:44:24 by daegulee          #+#    #+#             */
/*   Updated: 2022/07/14 21:45:04 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	update_w_down(t_pack *pack, char *arg)
{
	write_update(pack, arg);
	(pack -> width)--;
}

void	write_update(t_pack *pack, char *arg)
{
	write(1, arg, 1);
	(pack -> result_length)++;
}
