/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 03:53:08 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/19 15:16:46 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "../parser/lexer/lexer.h"
# include "../parser/parser/parser.h"
# include <unistd.h>
# include <dirent.h>
# include <errno.h>

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

//queue
t_qnode	*new_qnode(char c);
t_queue	*init_queue(void);
void	push_queue(t_queue *queue, t_qnode *new);
t_qnode	*pop_queue(t_queue *queue);
t_queue	*init_str_queue(char *str);
void	free_queue(t_queue *queue);

//expand_wild
char	look_q_not_asterisk(t_queue *queue);
int		is_wild(char *wild_str, char *check);
int		wild_check_part(t_queue	*wild_queue, int *i, char *check);
void	wild_expand_finish(char **argv, int i, char *wild_str, char *cur_wdir);
char	**wild_expand(char *wild_str);

#endif