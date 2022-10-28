/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_expand2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:09:31 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/24 14:17:16 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./execute.h"

void	wild_expand_finish(char **argv, int i, char *wild_str, char *cur_wdir)
{
	if (i)
		argv[i] = NULL;
	else
	{
		argv[0] = ft_strdup(wild_str);
		argv[1] = NULL;
	}
	free(cur_wdir);
}
