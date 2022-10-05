/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:33:58 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/04 09:49:42 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include"../parser/lexer/lexer.h"

typedef enum e_type_data
{
	STATUS = 0,
	TOKEN,
	NON_T
}	t_type_data;

typedef struct s_stack_data
{
	t_token				*token;
	t_type_data			type;
	int					state;
	int					n_terminal_type;
}	t_stack_data;

typedef struct s_node
{
	t_stack_data	*data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		count;
	t_node	*head;
}	t_stack;

void	ft_push(t_stack *st, t_node *target);
t_node	*ft_pop(t_stack *st);
t_node	*ft_peek(t_stack *st);
#endif
