/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:42 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/19 14:34:00 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"

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
