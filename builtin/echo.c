/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:35:06 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 01:26:13 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"

int	mini_echo(char **argv)
{
	int	n_idx;

	n_idx = 1;
	if (argv == NULL || argv_len(argv) <= 0)
		return (printf("\n") - 1);
	if (ft_strcmp(argv[1], "-n") == 0)
	{
		while (ft_strcmp(argv[n_idx], "-n") == 0)
			n_idx++;
		while (argv[n_idx])
		{
			printf("%s", argv[n_idx]);
			if (argv[n_idx] && argv[n_idx + 1])
				printf(" ");
			n_idx++;
		}
		return (0);
	}
	while (argv[n_idx])
		printf("%s ", argv[n_idx++]);
	printf("\n");
	return (0);
}
