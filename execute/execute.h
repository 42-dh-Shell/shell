/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:07:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/21 20:27:56 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# include "../libft/libft.h"
# include "../parser/parser/parser.h"
# include "../hash/hash.h"
# include "../builtin/builtin.h"
# include "../minishell.h"
# include "../error_printf/error_printf.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <errno.h> 
# define COMM_ERROR "minishell : command not found: "

typedef enum e_command_io
{
	C_WRITE = 0,
	C_READ,
	C_NORMAL,
	C_RW
}	t_command_io;

typedef struct s_pids
{
	pid_t			pid;
	struct s_pids	*next;
}	t_pid_list;

extern	t_shell	*g_shell;

int		has_event(t_ast_node *head);
void	add_last_pid(pid_t pid, t_pid_list **pids);
void	execute_command(t_ast_node *head, int fd_pipe[], \
	t_command_io io, t_pid_list **pids);
void	execute_command_handler(t_ast_node *head, int fd_pipe[], \
	t_command_io io, t_pid_list **pids);
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
void	execute(t_ast_node *head, char **argv);
char	**get_envp(void);
void	wait_all_pids(t_pid_list **pids);
int		is_last_pipe(t_ast_node *head);
void	dup_pipe(t_command_io io, int fd_pipe[]);
void	execute_and_or_handler(t_ast_node *head, t_pid_list **pids);
void	execute_subsehll_handler(t_ast_node *head, int fd_pipe[], \
	t_command_io io, t_pid_list **pids);
int		builtin_handler(t_ast_node *head, t_command_io io, int echo_flag);
char	*get_envp_path(void);
void	execute_builtin(t_ast_node *head, char **argv, t_command_io io);
void	print_no_file_error(char *filename);
void	release_pid_list(t_pid_list	*pids);
#endif