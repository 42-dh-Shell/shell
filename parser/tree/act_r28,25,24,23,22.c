/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_r28,25,24,23,22.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:01:24 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/11 18:22:28 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

void	act_r28(t_support *sup)
{
	sup->wait->io_redir = ft_malloc(sizeof(t_redir));
	sup->wait->io_redir->f_name = sup->wait->f_name;
	sup->wait->io_redir->rd_t = LESS;
	sup->wait->f_name = NULL;
}

void	act_r25(t_support *sup)
{
	t_redir	*cur;

	cur = sup->wait->rd_lst->head;
	while (cur->next)
		cur = cur->next;
	cur->next = sup->wait->io_redir;
	sup->wait->io_redir = NULL;
}

void	act_r24(t_support *sup)
{
	sup->wait->rd_lst = ft_malloc(sizeof(t_redir_lst));
	sup->wait->rd_lst->head = sup->wait->io_redir;
	sup->wait->io_redir = NULL;
}

void	act_r23(t_support *sup)
{
	t_redir	*cur;

	cur = sup->wait->cmd_pref->head;
	while (cur->next)
		cur = cur->next;
	cur->next = sup->wait->io_redir;
	sup->wait->io_redir = NULL;
}

void	act_r22(t_support *sup)
{
	sup->wait->cmd_pref = ft_malloc(sizeof(t_cmd_pre));
	sup->wait->cmd_pref->head = sup->wait->io_redir;
	sup->wait->io_redir = NULL;
}
