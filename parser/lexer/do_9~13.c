/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_9~13.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:28:38 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 06:06:18 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	do_s9(t_auto_data *data)
{
	(data->str)++;
	data->prev_state = data->next_state;
	data->next_state = L_S17;
}

void	do_s10(t_auto_data *data)
{
	(data->str)++;
	data->prev_state = data->next_state;
	data->next_state = L_S17;
}

void	do_s11(t_auto_data *data)
{
	(data->str)++;
	data->prev_state = data->next_state;
	if (get_char_status(*(data->str)) == BIT_AND)
		data->next_state = L_S12;
	else
		data->next_state = L_S13;
}

void	do_s12(t_auto_data *data)
{
	(data->str)++;
	data->prev_state = data->next_state;
	data->next_state = L_S17;
}

void	do_s13(t_auto_data *data)
{
	if (data->prev_state == L_S1)
		printf("minishell : syntax error.\n");
	else if (data->prev_state == L_S2 || \
	data->prev_state == L_S3)
	{
		printf("minishell : Unclosed Quote!.\n");
	}
	else
		printf("minishell : Unsupported Token &.\n");
}
