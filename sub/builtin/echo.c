/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:35:06 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/14 15:48:36 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"

int	echo(char **argv)
{
	int	n_idx;

	n_idx = 0;
	if (argv == NULL || !argv[0])
		return (printf("\n") - 1);
	if (str_equal(argv[0], "-n"))
	{
		while (str_equal(argv[n_idx], "-n"))
			n_idx++;
		while (argv[n_idx])
		{
			printf("%s", argv[n_idx]);
			if (argv[n_idx] && argv[n_idx + 1])
				printf(" ");
			n_idx++;
		}
		ft_free_split(argv);
		return (0);
	}
	while (argv[n_idx])
		printf("%s ", argv[n_idx++]);
	printf("\n");
	ft_free_split(argv);
	return (0);
}

int main()
{
	char	**split;

	split = ft_split("", ' ');
	echo(split);
	printf("%d", echo(split));

}
