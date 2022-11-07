/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:50:54 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/21 14:49:44 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_printf.h"

int	ft_isflag(char c)
{
	if (c == '-' || c == '+'
		|| c == '0' || c == ' ' || c == '#')
		return (1);
	else
		return (0);
}
