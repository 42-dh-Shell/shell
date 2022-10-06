/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lalr_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:11:50 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/06 23:44:38 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static const t_string	*g_lalr_table[TABLE_HEIGHT];

void	make_lalr_table(void)
{
	int			i;
	int			table_fd;
	char		*str;
	static int	first;

	if (first != 0)
		return ;
	table_fd = open("./parser/parser/table.txt", O_RDONLY);
	if (table_fd < 0)
		ft_exit(NULL, 1);
	i = -1;
	while (++i < TABLE_HEIGHT)
	{
		str = get_next_line(table_fd);
		if (str == NULL)
			ft_exit("malloc error.\n", 1);
		g_lalr_table[i] = ft_split(str, '\t');
		free(str);
	}
	close(table_fd);
	first = 1;
}

int	get_action_idx(t_token_list *t_list)
{
	if (t_list->head->token_type == T_PIPE)
		return (ACTION_PIPE);
	else if (t_list->head->token_type == T_OR)
		return (ACTION_OR);
	else if (t_list->head->token_type == T_AND)
		return (ACTION_AND);
	else if (t_list->head->token_type == T_L_BRAKIT)
		return (ACTION_L_BRAKIT);
	else if (t_list->head->token_type == T_R_BRAKIT)
		return (ACTION_R_BRAKIT);
	else if (t_list->head->token_type == T_WORD)
		return (ACTION_WORD);
	else if (t_list->head->token_type == T_LESS)
		return (ACTION_WORD);
	else if (t_list->head->token_type == T_GREATE)
		return (ACTION_GREATE);
	else if (t_list->head->token_type == T_DGREATE)
		return (ACTION_DGREATE);
	else if (t_list->head->token_type == T_DLESS)
		return (ACTION_DLESS);
	else if (t_list->head->token_type == T_BOT)
		return (ACTION_BOTTOM);
}

// // int	get_goto_idx(t_stack *stack)
// // {

// // }

// // char	*look_lalr_goto(t_stack *stack, char *str, e)
// // {
// // 	make_lalr_table();
// // 	str = g_lalr_table[stack->top->state][get_action_idx(t_list)];
// // 	return (str);
// }

char	*look_lalr_action(t_stack *stack, char *str, t_token_list *t_list)
{
	make_lalr_table();
	str = g_lalr_table[stack->top->state][get_action_idx(t_list)];
	return (str);
}
