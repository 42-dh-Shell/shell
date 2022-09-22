/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:50:23 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/09 19:53:20 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
