/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:36:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/05 20:41:11 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_exit(const char *str, int exit_flag)
{
	if (str)
	{
		ft_putstr_fd("\033[31mError : ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\033[0m", 2);
	}
	else
		perror("bash");
	exit(exit_flag);
}
