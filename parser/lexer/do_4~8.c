/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_4~8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:08:53 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 14:24:30 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	do_s4(t_auto_data *data)
{
	t_exps	*new;
	int		first;

	new = NULL;
	first = 1;
	while (first || is_expansion(*(data->str)))
	{
		fill_buffer_exps(data, &new);
		(data->str)++;
		first = 0;
	}
	(new->str)[new->end - new->start] = 0;
	(new->end)--;
	data->next_state = data->prev_state;
	data->prev_state = L_S4;
	exps_lst_addback(&(data->exps_list), new);
}

void	do_s5(t_auto_data *data)
{
	(data->str)++;
	data->prev_state = data->next_state;
	if (get_char_status(*(data->str)) == RIGHT_ARROW)
		data->next_state = L_S6;
	else
		data->next_state = L_S17;
}

void	do_s6(t_auto_data *data)
{
	(data->str)++;
	data->prev_state = data->next_state;
	data->next_state = L_S17;
}

void	do_s7(t_auto_data *data)
{
	(data->str)++;
	data->prev_state = data->next_state;
	if (get_char_status(*(data->str)) == LEFT_ARROW)
		data->next_state = L_S8;
	else
		data->next_state = L_S17;
}

void	do_s8(t_auto_data *data)
{
	(data->str)++;
	data->prev_state = data->next_state;
	data->next_state = L_S17;
}
