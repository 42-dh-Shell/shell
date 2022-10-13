/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:35:06 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/13 16:26:40 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"

int	echo(char **argv)
{
	int	i;

	i = -1;
	while (argv != NULL && argv[++i])
		printf("%s ", argv[i]);
	printf("\n");
	ft_free_split(argv);
	return (0);
}
