/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:48:04 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/17 13:07:14 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../hash/hash.h"
# include "../parser/lexer/lexer.h"
# include "../libft/libft.h"
# include "../signal/signal.h"

typedef struct s_shell
{
	t_hash		*h_table;
	int			exit_status;
	int			sh_lv;
}	t_shell;

void	start_parse(char *line);
#endif