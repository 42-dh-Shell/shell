/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:07:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/19 17:10:48 by hyunkyle         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# define COMM_ERROR "minishell : command not found: "

typedef enum e_command_io
{
	C_WRITE = 0,
	C_READ,
	C_NORMAL
}	t_command_io;

typedef struct s_pids
{
	pid_t			pid;
	int				status;
	struct s_pids	*next;
}	t_pid;

extern	t_shell	*g_shell;

int		has_event(t_ast_node *head);
pid_t	execute_command(t_ast_node *head, int fd_pipe[], \
	t_command_io io);
int		get_argv_size(char **argv);
char	**expand_str(char *node_str, t_expand_info *expand_info);
void	get_expand_str(char *str, t_expand_info *expand_info, \
	char *node_str, int i);
int		get_expand_argv_size(char *str, t_expand_info *expand_info);
void	argv_expand(char **result, t_expand_info *expand_info, char *str);
char	**argv_no_expand(char *str);
char	**get_argv(char *str, t_expand_info *expand_info, char *node_str);
char	*get_expand_value(t_expand_info *expand_info);
void	dup_fd(char *filename, enum	e_ast_types type);
void	execute_redir(t_ast_node *head);
char	**get_command_info(t_ast_node *head);
void	execute_make_fullpath(char **argv, char *envp);
void	execute_fullpath(char **argv);
char	*get_full_path(char *path, char *comm);
char	*get_valid_fullpath(char **paths, char **argv);
void	execute_fullpath_handler(char **argv);
int		is_valid_command(char *command);
int		is_valid_redir_filename(t_expand_info *expand_info);
void	execute(t_ast_node *head, int fd_pipe[], t_command_io io);
char	**get_envp(void);
#endif