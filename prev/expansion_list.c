/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:12:58 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/26 19:59:03 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	exps_add_back(t_exps_info **lst, t_exps_info *new)
{
	t_exps_info	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (!(last->next == NULL))
		last = last->next;
	last->next = new;
}

void	init_exps_list(t_auto_data *data, t_exps_info *list)
{
	t_exps_info	*cur;

	cur = malloc(sizeof(t_exps_info));
	if (cur == NULL)
		ft_exit("Malloc ㅠㅠ\n", 1);
	ft_memset(cur, 0, sizeof(t_exps_info));
	ft_memset(cur->str, 0, sizeof(WORD_SIZE_MAX));
	cur->start = data->buffer_idx;
	cur->end = data->buffer_idx;
	exps_add_back(&list, cur);
}

void	fill_exps_list(t_auto_data *data, t_exps_info *list)
{
	list->str[data->buffer_idx - list->start] = \
	(data->buffer)[data->buffer_idx];
	list->end = data->buffer_idx;
}

void	fill_buffer(t_auto_data *data)
{
	(data->buffer)[data->buffer_idx] = *(data->str);
	(data->buffer_idx)++;
	(data->str)++;
}

int	change_next_state(t_auto_data *data, int state)
{
	data->next_state = state;
	return (1);
}
