/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:33:49 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/07 10:27:33 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser/stack/stack.h"
#include "./parser/parser/parser.h"
#include "./parser/stack/stack.h"

int	main()
{
	t_token_list	*t_list;
	char			*str;
	t_stack			*stack;

	t_list = lexer("cat hello | hi");
	stack = init_stack();
	str = look_lalr_action(stack, str, t_list);
	printf("first lalr %s\n ", str);
}