/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:07:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/18 14:21:49 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# include "../libft/libft.h"
# include "../parser/parser/parser.h"
# include "../hash/hash.h"
# include "../minishell.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef enum e_command_io
{
	C_WRITE = 0,
	C_READ,
	C_NORMAL
}	t_command_io;

extern	t_shell	*g_shell;

int		has_event(t_ast_node *head);
void	execute_command(t_ast_node *head, int fd_pipe[], \
			t_command_io io);
int		get_argv_size(char **argv);
char	**expand_str(char *node_str, t_expand_info *expand_info);
void	get_expand_str(char *str, t_expand_info *expand_info, \
	char *node_str, int i);
int		get_expand_argv_size(char *str, t_expand_info *expand_info);
void	argv_expand(char **result, t_expand_info *expand_info, char *str);
char	**argv_no_expand(char *str);
char	**get_argv(char *str, t_expand_info *expand_info, char *node_str);
#endif