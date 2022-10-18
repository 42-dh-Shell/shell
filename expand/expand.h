/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 03:53:08 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 20:21:53 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "../parser/lexer/lexer.h"
# include "../parser/parser/parser.h"
# include "../string/mystring.h"

typedef struct s_qnode
{	
	char			c;
	struct s_qnode	*back;
}	t_qnode;

typedef struct t_queue
{
	int		len;
	t_qnode	*front;
	t_qnode	*tail;
}	t_queue;

#endif