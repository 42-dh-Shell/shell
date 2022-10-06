/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:25:34 by daegulee          #+#    #+#             */
/*   Updated: 2022/07/23 17:29:01 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_endl(char *prev, int *len, t_buflst *cur)
{
	char	*str;
	int		i;

	if (cur->nul == 1 || (cur->len == 0 && *len == 0))
		return (NULL);
	str = (char *)malloc(sizeof(char) * (*len + cur->len));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < *len)
		str[i] = prev[i];
	free(prev);
	i = 0;
	while (i < cur->len && cur->buffer[i] != '\n')
	{
		str[*len + i] = cur->buffer[i];
		i++;
	}
	*len += i;
	pushbuf(cur, i);
	return (terminate(str, len, cur));
}

void	pushbuf(t_buflst *cur, int pushlen)
{
	int	i;

	i = 0;
	if (cur->l_exist)
	{
		while (i < (cur->len - pushlen - 1))
		{
			cur->buffer[i] = cur->buffer[i + pushlen + 1];
			i++;
		}
		cur->len -= (pushlen + 1);
	}
}

int	get_remain(t_buflst *cur, int *len, char **str)
{
	int		i;

	i = 0;
	if (cur->l_exist || (!cur->len && !cur->l_exist))
	{
		*len = 0;
		*str = NULL;
		return (1);
	}
	else
	{
		*str = (char *)malloc(sizeof(char) * cur->len);
		if (*str == NULL)
			return (0);
		while (i < cur->len)
		{
			(*str)[i] = cur->buffer[i];
			i++;
		}
		*len = cur->len;
		cur->len = 0;
		return (1);
	}
}

void	clear(t_buflst *new, int fd)
{
	new->next = NULL;
	new->len = 0;
	new->fd = fd;
	new->l_exist = 0;
	new->nul = 0;
}

t_buflst	*find(t_buflst **buflst, int fd)
{
	t_buflst	*iter;
	t_buflst	*new;

	iter = *buflst;
	if (*buflst == NULL)
	{
		*buflst = (t_buflst *)malloc(sizeof(t_buflst));
		if (*buflst == NULL)
			return (NULL);
		clear(*buflst, fd);
		return (*buflst);
	}
	while (iter->next && iter->fd != fd)
		iter = iter->next;
	if (iter->fd != fd)
	{
		new = (t_buflst *)malloc(sizeof(t_buflst));
		if (new == NULL)
			return (NULL);
		clear(new, fd);
		iter->next = new;
		return (new);
	}
	return (iter);
}
