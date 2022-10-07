/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:53:58 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/07 21:06:37 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
// push_down automata 이후에 토큰리스트 프리 푸시다운은 로컬로 들고감 

void	push_down(t_stack *stack, t_token_list t_list);

void	parser(char *str)
{
	t_token_list	*t_list;
	t_stack			*stack;

	t_list = lexer(str);
	stack = init_stack();
	push_down(stack, *t_list);
}

void	push_down(t_stack *stack, t_token_list t_list)
{
	char			*str;

	str = NULL;
	str = look_lalr_action(stack, str, &t_list);
	while (!str_equal(str, "N") && !str_equal(str, "A"))
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
		if (ft_strnstr(str, "s", ft_strlen(str)) != NULL)
			stack_shift(&str, stack, &t_list);
		else
			stack_reduce(&str, stack, &t_list);
	}
	printf("last ! %s\n", str);
}
