/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_exps_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:49:26 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/28 17:12:52 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

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

int	is_expansion(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || \
	(c >= '0' && c <= '9') || (c == '_'));
}

void	fill_buffer_exps(t_auto_data *data, t_exps **exps)
{
	if (*exps == NULL)
	{
		*exps = malloc(sizeof(t_exps));
		if (*exps == NULL)
			ft_exit("malloc error.\n", 2);
		ft_memset(*exps, 0, sizeof(t_exps));
		(*exps)->start = data->buffer_idx;
		(*exps)->end = data->buffer_idx;
		(*exps)->str = malloc(sizeof(char) * (ft_strlen(data->str) + 1));
		if (data->prev_state == L_S2)
			(*exps)->is_quote = 1;
		if ((*exps)->str == NULL)
			ft_exit("malloc error.\n", 2);
	}
	(data->buffer)[data->buffer_idx] = *(data->str);
	(data->buffer_idx)++;
	((*exps)->str)[(*exps)->end - (*exps)->start] = *(data->str);
	((*exps)->end)++;
}
