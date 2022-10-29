/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:07:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/29 22:22:41 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# include "../libft/libft.h"
# include "../parser/parser/parser.h"
# include "../parser/lexer/lexer.h"
# include "../hash/hash.h"
# include "../builtin/builtin.h"
# include "../minishell.h"
# include "../error_printf/error_printf.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h> 
# define COMM_ERROR "minishell : command not found: "

typedef enum e_command_io
{
	C_READ = 0,
	C_WRITE,
	C_NORMAL,
	C_RW
}	t_command_io;

typedef struct s_qnode
{	
	char			c;
	struct s_qnode	*back;
}	t_qnode;

typedef struct t_queue
{
	int		len;
	t_qnode	*front;
	t_qnode	*tail;
}	t_queue;

extern t_shell	*g_shell;

int		has_event(t_ast_node *head);
void	add_last_pid(pid_t pid);
void	execute_command(t_ast_node *head, int fd_pipe[], \
	int next_pipe[], t_command_io io);
void	execute_command_handler(t_ast_node *head, int fd_pipe[], \
	int next_pipe[], t_command_io io);
int		get_argv_size(char **argv);
char	**expand_str(char *node_str, t_expand_info *expand_info);
void	get_expand_str(char *str, t_expand_info *expand_info, \
	char *node_str, int i);
int		get_expand_argv_size(char *str, t_expand_info *expand_info);
void	argv_expand(char **result, t_expand_info *expand_info, char *str);
char	**argv_no_expand(char *str);
char	**get_argv(char *str, t_expand_info *expand_info, char *node_str);
char	*get_expand_value(t_expand_info *expand_info);
void	dup_pipe(t_command_io io, int fd_pipe[], int next_pipe[]);
void	execute_redir(t_ast_node *head);
char	**get_command_info(t_ast_node *head);
void	execute_make_fullpath(char **argv, char *envp);
void	execute_fullpath(char **argv);
char	*get_full_path(char *path, char *comm);
char	*get_valid_fullpath(char **paths, char **argv);
void	execute_fullpath_handler(char **argv);
int		is_valid_command(char *command);
int		is_valid_redir_filename(t_expand_info *expand_info);
void	execute(t_ast_node *head);
char	**get_envp(void);
void	wait_all_pids(void);
int		is_last_pipe(t_ast_node *head);
void	dup_pipe(t_command_io io, int fd_pipe[], int next_pipe[]);
void	execute_and_or_handler(t_ast_node *head);
void	execute_subsehll_handler(t_ast_node *head, int fd_pipe[], \
	int next_pipe[], t_command_io io);
int		builtin_handler(t_ast_node *head, t_command_io io, int echo_flag);
char	*get_envp_path(void);
void	execute_builtin(t_ast_node *head, t_command_io io);
void	print_no_file_error(char *filename);
void	release_pid_list(t_pid_list	*pids);
void	close_pipe(int fd_pipe[2], int idx);
void	store_io(void);
char	*get_io_filename(int in_out_flag);
void	parent_free_all_pipe_lst(void);
void	close_all_pipe(void);
void	do_pipe_list(int fd[]);
void	expand_exit_status(char **argv);
void	dup_child(t_ast_node *head);

//queue
t_qnode	*new_qnode(char c);
t_queue	*init_queue(void);
void	push_queue(t_queue *queue, t_qnode *new);
t_qnode	*pop_queue(t_queue *queue);
t_queue	*init_str_queue(char *str);
void	free_queue(t_queue *queue);

//expand_wild
char	look_q_not_asterisk(t_queue *queue);
int		is_wild(char *wild_str, char *check);
int		wild_check_part(t_queue	*wild_queue, int *i, char *check);
void	wild_expand_finish(char **argv, int i, char *wild_str, char *cur_wdir);
char	**wild_expand(char *wild_str);

//fix
void	get_expd_str_help(char *str, t_expand_info *expand_info, \
	char *value, int i);
#endif
