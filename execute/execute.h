/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:07:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/17 17:07:06 by hyunkyle         ###   ########.fr       */
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
#endif