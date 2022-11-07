/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:23:12 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/13 19:58:35 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdio.h>

void	ft_color_printf(const char *str)
{
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\033[0m", 2);
}

void	ft_color_printft2(const char *str)
{
	ft_putstr_fd("\033[31m", 1);
	printf("minishell : syntax error near unexpected token '%s'\n", str);
	ft_putstr_fd("\033[0m", 1);
}
