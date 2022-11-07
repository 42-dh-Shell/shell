/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:00:37 by daegulee          #+#    #+#             */
/*   Updated: 2022/11/07 21:11:15 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <termios.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../minishell.h"

extern t_shell	*g_shell;

void	sigint_exit(int signum)
{
	if (signum == SIGINT)
		g_shell->exit_status = 130;
}
