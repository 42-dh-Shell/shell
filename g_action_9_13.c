/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_action_9_13.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:23:13 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/26 15:45:32 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	do_s9(t_auto_data *data)
{
	if (!(*(data->str)))
		printf("Syntax Error.\n");
	else if (data->buffer_idx == WORD_SIZE_MAX)
		printf("File Name Too long.\n");
	else
		printf("Tokenizing Error.\n");
}

void	do_s10(t_auto_data *data)
{
	(data->str)++; // ( 감기
	data->type = L_S10;
	data->state = L_S12;
}

void	do_s11(t_auto_data *data)
{
	(data->str)++; // ) 감기
	data->type = L_S11;
	data->state = L_S12;
}

void	do_s12(t_auto_data *data)
{
	memset(data, 0, sizeof(t_auto_data));
}
