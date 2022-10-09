/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:31:51 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/09 19:43:48 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static const t_fp	g_action[18] = {
	do_s0, do_s1, do_s2, do_s3, do_s4, do_s5, do_s6, do_s7, do_s8, \
	do_s9, do_s10, do_s11, do_s12, do_s13, do_s14, do_s15, do_s16, \
	do_s17
};

t_token	*last_token(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(token, 0, sizeof(t_token));
	token->token_type = T_BOT;
	return (token);
}

t_token_list	*lexer(char *str)
{
	t_token_list	*t_list;
	t_token			*new;
	int				i;

	i = 0;
	t_list = malloc(sizeof(t_token_list));
	if (t_list == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(t_list, 0, sizeof(t_token_list));
	while (*str)
	{
		i++;
		new = automata(&str);
		if (new != NULL)
			t_list_addback(t_list, new);
	}
	if (t_list->head != NULL)
		t_list_addback(t_list, last_token());
	if (t_list->head == NULL)
	{
		free(t_list);
		return (NULL);
	}
	print_token(t_list);
	return (t_list);
}

void	init_auto(t_auto_data **data, char *str)
{
	int	i;

	i = -1;
	*data = malloc(sizeof(t_auto_data));
	if (data == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(*data, 0, sizeof(t_auto_data));
	(*data)->str = str;
	(*data)->buffer = malloc(sizeof(char) * (ft_strlen(str) + 1));
	(*data)->prev_state = L_S1;
	(*data)->next_state = L_S0;
	if ((*data)->buffer == NULL)
		ft_exit("malloc error.\n", 1);
}

t_token	*automata(char **str)
{
	t_auto_data	*data;
	t_token		*token;

	token = NULL;
	init_auto(&data, *str);
	while ((data->next_state != L_S17 && data->next_state != L_S13))
		g_action[data->next_state](data);
	g_action[data->next_state](data);
	data->buffer[data->buffer_idx + 1] = 0;
	if (data->type != L_S0)
		token = init_token(data);
	*str = (data->str);
	return (token);
}
