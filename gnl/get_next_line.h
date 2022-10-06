/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:22:32 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/07 14:42:31 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# include "unistd.h"
# include "stdlib.h"

typedef struct s_buflst
{
	struct s_buflst	*next;
	int				len;
	int				fd;
	char			buffer[BUFFER_SIZE];
	int				l_exist;
	int				nul;

}	t_buflst;

char		*terminate(char *prev, int *len, t_buflst *cur);
void		release(t_buflst **buflst, t_buflst *target);
char		*get_next_line(int fd);
char		*addstr(char *prev, int *len, t_buflst *cur);
int			read_bufsize(t_buflst *cur, int fd);
char		*get_endl(char *prev, int *len, t_buflst *cur);
void		pushbuf(t_buflst *cur, int pushlen);
int			get_remain(t_buflst *cur, int *len, char **str);
void		clear(t_buflst *new, int fd);
t_buflst	*find(t_buflst **buflst, int fd);

#endif