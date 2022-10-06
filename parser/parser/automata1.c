/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:42:37 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/06 17:48:20 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"
#include "../../stack/stack.h"

int	get_y_idx(t_token *tokens)
{
	if (tokens->token_type == WORD)
		return (IDX_WORD);
	else if (tokens->token_type == LBRAC)
		return (IDX_LBRAC);
	else if (tokens->token_type == RBRAC)
		return (IDX_RBRAC);
	else if (tokens->token_type == LESS)
		return (IDX_LESS);
	else if (tokens->token_type == GREAT)
		return (IDX_GREAT);
	else if (tokens->token_type == DLESS)
		return (IDX_DLESS);
	else if (tokens->token_type == DGREAT)
		return (IDX_DGREAT);
	else if (tokens->token_type == PIPE)
		return (IDX_PIPE);
	else if (tokens->token_type == OR)
		return (IDX_OR);
	else if (tokens->token_type == AND)
		return (IDX_AND);
	else
		return (IDX_LAST);
}

int	get_reduce_num(int reduce_num)
{
	if (reduce_num == 1 || reduce_num == 8 || reduce_num == 9 \
		|| reduce_num == 14 || reduce_num == 15 || reduce_num == 17 \
		|| reduce_num == 18 || reduce_num == 20 || reduce_num == 22 \
		|| reduce_num == 24 || reduce_num == 26 || reduce_num == 27 \
		|| reduce_num == 32 || reduce_num == 33)
		return (1);
	else if (reduce_num == 11 || reduce_num == 12)
		return (3);
	else
		return (2);
}

int	get_reduce_grammer_util(int reduce_tg)
{
	if (26 <= reduce_tg && reduce_tg <= 27)
		return (IDX_IO_REDIR);
	else if (28 <= reduce_tg && reduce_tg <= 30)
		return (IDX_IO_FILE);
	else if (reduce_tg == 31)
		return (IDX_IO_HERE);
	else if (reduce_tg == 32)
		return (IDX_F_NAME);
	else
		return (IDX_END);
}

int	get_reduce_grammer(int reduce_tg)
{
	if (1 <= reduce_tg && reduce_tg <= 4)
		return (IDX_DATA_LIST);
	else if (reduce_tg == 5)
		return (IDX_N_PIPE);
	else if (reduce_tg == 6)
		return (IDX_N_OR);
	else if (reduce_tg == 7)
		return (IDX_N_AND);
	else if (8 <= reduce_tg && reduce_tg <= 10)
		return (IDX_CMD);
	else if (reduce_tg == 11)
		return (IDX_SUBSHELL);
	else if (12 <= reduce_tg && reduce_tg <= 16)
		return (IDX_SIMPLE_COMMAND);
	else if (reduce_tg == 17)
		return (IDX_CMD_NAME);
	else if (18 <= reduce_tg && reduce_tg <= 21)
		return (IDX_CMD_SUFFIX);
	else if (22 <= reduce_tg && reduce_tg <= 23)
		return (IDX_CMD_PREFIX);
	else if (reduce_tg == 24 || reduce_tg == 25)
		return (IDX_REDIR_LIST);
	else
		return (get_reduce_grammer_util(reduce_tg));
}
