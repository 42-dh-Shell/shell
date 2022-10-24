/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:48:04 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/24 13:59:13 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "./hash/hash.h"
# include "./get_next_line/get_next_line_bonus.h"
# include "./parser/parser/parser.h"

typedef struct s_pids
{
	pid_t			pid;
	struct s_pids	*next;
}	t_pid_list;

typedef struct s_shell
{
	t_hash		*h_table;
	int			exit_status;
	int			sh_lv;
	char		*tmp;
	char		***lr_table;
	char		*io_filename[2];
	t_ast_node	*redir_list;
	int			std_io[2];
	t_pid_list	*pids;
}	t_shell;

char	*get_key(char *str);
char	*get_value(char *str);
char	***make_table(void);
#endif