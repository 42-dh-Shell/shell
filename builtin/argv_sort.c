/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:22:07 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 00:26:07 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"

int	argv_len(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL)
		return (0);
	while (argv[i])
		i++;
	return (i);
}

void	do_sort(char **str, char argc)
{
	int		sp;
	int		i;
	char	*tmp;

	sp = 0;
	i = 0;
	while (i < argc)
	{
		if (ft_strcmp(str[sp], str[i]) >= 0)
			sp = i;
		i++;
	}
	tmp = str[0];
	str[0] = str[sp];
	str[sp] = tmp;
	if (argc > 1)
		do_sort(&str[1], argc - 1);
}

void	argv_sort(char **argv)
{
	const int	argc = argv_len(argv);
	int			i;

	if (argc <= 1)
		return ;
	i = -1;
	do_sort(argv, argc);
}