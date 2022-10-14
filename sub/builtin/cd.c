/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:26:09 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/14 16:46:01 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"
// pwd - oldpwd chdir
// . cur
// .. back 
// ... -> error bash: cd: ...: No such file or directory

// ~,no input home
int	cd(char **argv)
{
	g_shell->h_table;
}
