/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:26:28 by daegulee          #+#    #+#             */
/*   Updated: 2022/11/07 14:37:33 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../libft/libft.h"
# include "../hash/hash.h"
# include <stdio.h>
# include <string.h>
# include "../error_printf/error_printf.h"
# include "../parser/parser/parser.h"

# define NO_EXEC_CHDIR 2

typedef int	(*t_built_f)(char **argv);

int			mini_cd(char **argv);
int			argv_len(char **argv);
void		set_env_in_ht(int ch_dir);
int			mini_env(char **argv);
void		argv_sort(char **argv);
int			mini_export(char **argv);
int			mini_echo(char **argv);
int			mini_unset(char **argv);
int			mini_pwd(char **argv);
int			is_builtin(char	**argv);
int			do_builtin(char	**argv);
int			mini_exit(char **argv);
void		release_argv(char **argv);
int			mini_exit_status(char **argv);
#endif
