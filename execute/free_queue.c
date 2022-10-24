/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:42 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/24 14:16:58 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./execute.h"

void	free_queue(t_queue *queue)
{
	t_qnode	*tmp;

	while (queue->front)
	{
		tmp = queue->front;
		queue->front = queue->front->back;
		free(tmp);	
	}
	free(queue);
}
