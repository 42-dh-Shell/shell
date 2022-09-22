/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:04:37 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/09/22 20:13:24 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

void	singnal_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

static void	term_set(void)
{
	struct termios	setting;

	tcgetattr(0, &setting);
	setting.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &setting);
}

void	set_signal_term(void)
{
	term_set();
	signal(SIGINT, singnal_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	print_exit(void)
{
	printf("\033[1A\033[5Cexit\n");
	exit(0);
}