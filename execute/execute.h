/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:07:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/17 12:43:51 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# include "../libft/libft.h"
# include "../parser/parser/parser.h"
# include <fcntl.h>

typedef enum e_command_io
{
	C_WRITE = 0,
	C_READ,
	C_NORMAL
}	t_command_io;

int		has_event(t_ast_node *head);
void	execute_command(t_ast_node *head, int fd_pipe[], \
	t_command_io io);
#endif