/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:04:37 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/20 15:12:01 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>

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
	printf("\033[1A\033[11Cexit\n");
	exit(0);
}
