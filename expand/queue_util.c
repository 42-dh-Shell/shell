/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:49:39 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/19 14:23:54 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"

t_qnode	*new_qnode(char c)
{
	t_qnode	*qnode;

	qnode = ft_malloc(sizeof(t_qnode));
	qnode->c = c;
	return (qnode);
}

t_queue	*init_queue(void)
{
	t_queue	*queue;

	queue = ft_malloc(sizeof(t_queue));
	return (queue);
}

void	push_queue(t_queue *queue, t_qnode *new)
{
	if (queue->len == 0)
	{
		queue->front = new;
		queue->tail = new;
		(queue->len)++;
		return ;
	}
	queue->tail->back = new;
	queue->tail = new;
	(queue->len)++;
}

t_qnode	*pop_queue(t_queue *queue)
{
	t_qnode	*tmp;

	if (queue->len == 0)
		return (NULL);
	if (queue->len == 1)
	{
		(queue->len)--;
		tmp = queue->front;
		queue->front = NULL;
		queue->tail = NULL;
		return (tmp);
	}
	tmp = queue->front;
	queue->front = queue->front->back;
	(queue->len)--;
	return (tmp);
}

t_queue	*init_str_queue(char *str)
{
	int		i;
	t_queue	*queue;

	i = -1;
	queue = init_queue();
	while (str[++i])
		push_queue(queue, new_qnode(str[i]));
	return (queue);
}
