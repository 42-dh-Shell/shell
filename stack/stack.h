/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:37:42 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/29 00:08:14 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "../parser/lexer.h"

typedef struct s_node
{
	struct s_node	*bottom;
	t_token			*token;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

#endif
