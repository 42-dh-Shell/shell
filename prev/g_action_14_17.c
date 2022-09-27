/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_action_14_17.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:14:15 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/27 20:30:36 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	do_s14(t_auto_data *data)
{	
	(data->str)++; // | 감기
	data->prev_state = data->next_state;
	if (get_char_status(*(data->str)) == BIT_OR)
		data->next_state = L_S15;
	else
		data->next_state = L_S17;
}

void	do_s15(t_auto_data *data)
{	
	(data->str)++; // | 감기
	data->prev_state = data->next_state;
	data->next_state = L_S17;
}

void	do_s16(t_auto_data *data)
{
	(data->str)++; // is_space감기
	data->prev_state = data->next_state;
	data->next_state = L_S1;
}

void	do_s17(t_auto_data *data)
{
	data->type = data->prev_state;
}
