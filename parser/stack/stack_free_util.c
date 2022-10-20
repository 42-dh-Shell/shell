/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:03:13 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/20 15:47:10 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	free_snode(t_snode *snode)
{
	if (snode->token)
	{
		free(snode->token->token_data);
		free(snode->token);
	}
	free(snode);
}
