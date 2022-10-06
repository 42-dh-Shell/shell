/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:33:49 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/05 21:45:36 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser/stack/stack.h"

int	main()
{
	t_stack	*stack;

	stack = init_stack();
	printf("stack ->first %u\n", stack->top->state);
}