/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_r16,15,14,13,12.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:18:51 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/11 19:29:55 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

void	act_r16(t_support *sup)
{
	sup->wait->cmd = ft_malloc(sizeof(t_cmd));
	sup->wait->cmd->cmd_name = sup->wait->cmd_name;
	sup->wait->cmd->cmd_suffix = sup->wait->cmd_suf;
	sup->wait->cmd_name = NULL;
	sup->wait->cmd_suf = NULL;
}

void	act_r15(t_support *sup)
{
	sup->wait->cmd = ft_malloc(sizeof(t_cmd));
	sup->wait->cmd->cmd_name = sup->wait->cmd_name;
	sup->wait->cmd_name = NULL;
}

void	act_r14(t_support *sup)
{
	sup->wait->cmd = ft_malloc(sizeof(t_cmd));
	sup->wait->cmd->cmd_prefix = sup->wait->cmd_pref;
	sup->wait->cmd_pref = NULL;
}

void	act_r13(t_support *sup)
{
	sup->wait->cmd = ft_malloc(sizeof(t_cmd));
	sup->wait->cmd->cmd_prefix = sup->wait->cmd_pref;
	sup->wait->cmd->cmd_name = sup->wait->cmd_name;
	sup->wait->cmd_pref = NULL;
	sup->wait->cmd_name = NULL;
}

void	act_r12(t_support *sup)
{
	sup->wait->cmd = ft_malloc(sizeof(t_cmd));
	sup->wait->cmd->cmd_prefix = sup->wait->cmd_pref;
	sup->wait->cmd->cmd_name = sup->wait->cmd_name;
	sup->wait->cmd->cmd_suffix = sup->wait->cmd_suf;
	sup->wait->cmd_pref = NULL;
	sup->wait->cmd_name = NULL;
	sup->wait->cmd_suf = NULL;
}
