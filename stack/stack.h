/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:33:58 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/09/28 16:41:09 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_node
{
	void			*data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		count;
	t_node	*head;
}	t_stack;

void	ft_push(t_stack *st, t_node *target);
t_node	*ft_pop(t_stack *st);
#endif
