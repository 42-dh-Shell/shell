/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 22:08:42 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/28 00:12:31 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser/lexer.h"

int main(int argc, char **argv)
{
	int			i;
	t_token_list *t_list;
	t_token		 *cur;

	i = -1;
	argc = 0;
	t_list = lexer(argv[1]);
	cur = t_list->head;
	printf("argv ~~~~ %s\n", argv[1]);
	while (cur)
	{
		++i;
		printf("##########################\n");
		printf("cur%d token(data) %s.\
		token type(data) %d   ...", i,cur->token_data, cur->token_type);
		cur = cur->next;
	}
	printf("#### \n");
}
