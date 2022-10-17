/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:26:28 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 01:20:48 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../libft/libft.h"
# include "../hash/hash.h"
# include <stdio.h>
# include <string.h>

# define NO_EXEC_CHDIR 2

int		mini_cd(char **argv);
int		argv_len(char **argv);
void	set_env_in_ht(int ch_dir);
int		mini_env(void);
void	argv_sort(char **argv);
int		mini_export(char **argv);
int		mini_echo(char **argv);

#endif
