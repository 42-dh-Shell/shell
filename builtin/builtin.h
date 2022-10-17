/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:26:28 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/17 13:04:16 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../libft/libft.h"
# include "../hash/hash.h"
# include <stdio.h>
# include "../body/minishell.h"
# include <string.h>

extern	t_shell	*g_shell;
int		mini_cd(char **argv);
int		argv_len(char **argv);
void	set_env_in_ht(int ch_dir);

#endif
