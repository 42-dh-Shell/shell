/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:40:02 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/01 22:13:38 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

t_pipe_node	*new_pipe_node(int fd[])
{
	t_pipe_node	*new;

	new = ft_malloc(sizeof(t_pipe_node));
	new->fd = ft_malloc(sizeof(int *) * 2);
	(new->fd)[0] = fd[0];
	(new->fd)[1] = fd[1];
	return (new);
}

void	pipe_lst_addback(t_pipe_lst	*pipe_lst, t_pipe_node *new)
{
	t_pipe_node	*cur;

	if (pipe_lst->head == NULL)
	{
		pipe_lst->head = new;
		return ;
	}
	cur = pipe_lst->head;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

void	do_pipe_list(int fd[])
{
	if (g_shell->pipe_lst == NULL)
		g_shell->pipe_lst = ft_malloc(sizeof(t_pipe_lst));
	if (pipe(fd) < 0)
		ft_exit("pipe_error\n", 1);
	pipe_lst_addback(g_shell->pipe_lst, new_pipe_node(fd));
}

void	close_all_pipe(void)
{
	t_pipe_node	*cur;
	t_pipe_node	*tmp;

	if (g_shell->pipe_lst == NULL || g_shell->pipe_lst->head == NULL)
		return ;
	cur = g_shell->pipe_lst->head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		close_pipe(tmp->fd, 0);
		close_pipe(tmp->fd, 1);
		free(tmp->fd);
		free(tmp);
	}
	free(g_shell->pipe_lst);
	g_shell->pipe_lst = NULL;
}

void	parent_free_all_pipe_lst(void)
{
	t_pipe_node	*cur;
	t_pipe_node	*tmp;

	if (g_shell->pipe_lst == NULL)
		return ;
	cur = g_shell->pipe_lst->head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp->fd);
		free(tmp);
	}
	free(g_shell->pipe_lst);
	g_shell->pipe_lst = NULL;
}
