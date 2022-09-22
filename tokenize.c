/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:01:36 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/22 20:02:57 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const t_fp	g_action[2] = {
	do_s0, do_s1
};

int	is_alpha_digit(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') \
	|| (c >= '0' && c <= '9'));
}

int	is_space(char c)
{
	return (c >= 9 && c <= 13);
}

void	lex_automata(char *str)
{
	t_auto_data	data;
	int			i;

	i = -1;
	memset(&data, 0, sizeof(t_auto_data));
	data.str = str;
	while (data.state != L_S12 || data.state != L_S9 && *(data.str))
	{
		g_action[data.state](&data);
	}
}

int main(int argc, char **argv)
{
	argc = 1;
	lex_automata(argv[1]);
}