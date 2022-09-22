/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_action_04.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:04:10 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/22 15:55:46 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	do_s0(t_auto_data *data)
{
	if (is_alpha_digit(*(data->str)))
		data->state = L_S1;
	else if (*(data->str) == '\"')
		data->state = L_S2;
	else if (*(data->str) == '\'')
		data->state = L_S3;
	else if (*(data->str) == '|')
		data->state = L_S4;
	else if (*(data->str) == '&')
		data->state = L_S7;
	else
		return ;
}

void	do_s1(t_auto_data *data)
{
	static int i = 1;
	// if (data->buffer_idx >= WORD_SIZE_MAX)
	// 	ft_exit("Name is Too long\n", 1);
	(data->buffer)[data->buffer_idx] = *(data->str);
	(data->buffer_idx)++;
	// find next stat
	if (is_alpha_digit(*(data->str + 1)))
		data->state = L_S1;
	else if (*(data->str + 1) == '\"')
		data->state = L_S2;
	else if (*(data->str + 1) == '\'')
		data->state = L_S3;
	else
	{
		data->state = L_S12;
		// save type before finish
		data->type = L_S1;
		return ;
	}
		printf("%d\n", i);
	i++;
	printf("%c\n", *(data->str));
	(data->str)++;
	//
}

void	do_s2(t_auto_data *data)
{

}
