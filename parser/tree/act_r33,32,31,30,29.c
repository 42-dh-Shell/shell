/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_r33,32,31,30,29.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 06:46:56 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/11 18:31:37 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

void	act_r33(t_support *sup)
{
	sup->wait->end = token_dup(sup->stack->top->bottom->token);
}

void	act_r32(t_support *sup)
{
	sup->wait->f_name = token_dup(sup->stack->top->bottom->token);
}

void	act_r31(t_support *sup)
{
	sup->wait->io_redir = ft_malloc(sizeof(t_redir));
	sup->wait->io_redir->f_name = sup->wait->end;
	sup->wait->io_redir->rd_t = DLESS;
	sup->wait->f_name = NULL;
}

void	act_r30(t_support *sup)
{
	sup->wait->io_redir = ft_malloc(sizeof(t_redir));
	sup->wait->io_redir->f_name = sup->wait->f_name;
	sup->wait->io_redir->rd_t = DGREATE;
	sup->wait->f_name = NULL;
}

void	act_r29(t_support *sup)
{
	sup->wait->io_redir = ft_malloc(sizeof(t_redir));
	sup->wait->io_redir->f_name = sup->wait->f_name;
	sup->wait->io_redir->rd_t = GREATE;
	sup->wait->f_name = NULL;
}
