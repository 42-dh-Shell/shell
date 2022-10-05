/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:42:37 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/04 11:51:40 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"
#include "../../stack/stack.h"

// Build Node  -shift ->word
// Build Tree   -reduce ->tree
//  l -> ls -> | -> grep    ---- inputlist 
// 	

////
////
/// 	simple_cmd   				stack
//			|  
//  (cat)-> wo  
// cat  | ls  | grep 

//	<a <<a cat <b < ls   | ~ 	
//       
//					|
//			cmd
//		redir			cat ------------ 	
//	--------- 								
			//															
//			<<											<	
//  			a									<<		a
//  <			 								<		a
//		a									<		b
//										cmd		ls
//									cat a b c d

void	do_shift(t_stack *stack, t_token *tokens, int status)
{
	t_stack_data	*data;

	data = get_stack_data(tokens, TOKEN, -1, -1);
	ft_push(stack, get_stack_node(data));
	data = get_stack_data(0, STATUS, status, -1);
	ft_push(stack, get_stack_node(data));
}

int	do_reduce(t_stack *stack, char ***lalr_table, int cnt, int reduce_grammer)
{
	int		i;
	t_node	*node;
	t_node	*tg_node;
	char	*goto_action;

	i = 0;
	while (i != cnt)
	{
		node = ft_pop(stack);
		if (node->data->type != STATUS)
			i++;
		free(node->data);
		free(node);
	}
	node = ft_peek(stack);
	tg_node = get_stack_node(get_stack_data(0, NON_T, -1, reduce_grammer));
	ft_push(stack, tg_node);
	goto_action = lalr_table[node->data->state][reduce_grammer];
	if (goto_action[0] == 'N')
		return (0);
	tg_node = get_stack_node(get_stack_data(0, STATUS, \
				ft_atoi(goto_action, 0), -1));
	ft_push(stack, tg_node);
	return (1);
}

int	get_reduce_num(int reduce_num)
{
	if (reduce_num == 1 || reduce_num == 5 || reduce_num == 7 \
		|| reduce_num == 9 || reduce_num == 10 || reduce_num == 15)
		return (1);
	else if (reduce_num == 8)
		return (3);
	else
		return (2);
}

int	get_reduce_grammer(int reduce_tg)
{
	if (1 <= reduce_tg && reduce_tg <= 4)
		return (IDX_DATA_LIST);
	else if (5 <= reduce_tg && reduce_tg <= 7)
		return (IDX_SIMPLE_COMMAND);
	else if (reduce_tg == 8)
		return (IDX_SUBSHELL);
	else if (9 <= reduce_tg && reduce_tg <= 10)
		return (IDX_COMMAND_ELEM);
	else if (11 <= reduce_tg && reduce_tg <= 14)
		return (IDX_REDIR);
	else if (reduce_tg == 15)
		return (IDX_REDIR_WORD);
	else if (reduce_tg == 16)
		return (IDX_N_PIPE);
	else if (reduce_tg == 17)
		return (IDX_N_OR);
	else
		return (IDX_N_AND);
}
