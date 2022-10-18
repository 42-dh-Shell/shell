/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:12:35 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/18 11:36:22 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	has_event(t_ast_node *head)
{
	while (head)
	{
		if (head->node_type == NODE_SUBSHELL || head->node_type == NODE_AND \
			|| head->node_type == NODE_OR || head->node_type == NODE_PIPE)
			return (1);
		head = head->left;
	}
	return (0);
}

int	is_valid_redir_filename(t_expand_info	*expand_info, char **argv)
{
	char	*key;
	char	*value;

	if (expand_info == 0)
		return (1);
	while (expand_info)
	{
		if (expand_info->split_arg == 1)
		{
			key = ft_substr(expand_info->str, expand_info->start + 1, \
				expand_info->size);
			value = hash_get(g_shell->h_table, key);
			if (value != NULL && get_argv_size(ft_split(value, " ")) > 1)
			{
				printf("minishell: %s: ambiguous redirect\n", key);
				free(key);
				return (0);
			}
			free(key);
		}
		expand_info = expand_info->next;
	}
	return (1);
}

void	dup_fd(char *filename, e_ast_types type)
{
	int	fd;
	int	status;

	if (type == NODE_DGREAT)
		fd = open (filename, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else if (type == NODE_GREAT)
		fd = open (filename, O_CREAT | O_WRONLY, 0644);
	else if (type == NODE_LESS || type == NODE_DLESS)
		fd = open (filename, O_RDONLY);
	if (fd < 0)
	{
		printf ("minishell: no such file or directory: %s\n", filename);
		exit (1);
	}
	if (node_type == NODE_DGREAT || node_type == NODE_GREAT)
		status = dup2(fd, STDOUT_FILENO);
	else
		status = dup2(fd, STDIN_FILENO);
	if (status < 0)
		ft_exit ("dup2 error\n", 1);
}
