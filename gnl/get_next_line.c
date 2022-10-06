/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:25:28 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/09 16:46:08 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*terminate(char *prev, int *len, t_buflst *cur)
{
	char	*str;
	int		i;

	if (prev == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (*len + 2));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < *len)
		str[i] = prev[i];
	free(prev);
	if (cur->l_exist)
	{
		str[i] = '\n';
		str[i + 1] = 0;
		cur->l_exist--;
	}
	else
	{
		str[i] = 0;
		cur->len = 0;
	}
	return (str);
}

void	release(t_buflst **buflst, t_buflst *target)
{
	t_buflst	*prev;
	t_buflst	*cur;

	prev = NULL;
	cur = *buflst;
	if (*buflst == target)
	{
		*buflst = (*buflst)->next;
		free(cur);
		return ;
	}
	while (cur != target)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	free(cur);
	cur->nul = 0;
}

char	*get_next_line(int fd)
{
	static t_buflst	*buflst;
	char			*str;
	t_buflst		*cur;
	int				len;

	cur = find(&buflst, fd);
	if (cur == NULL)
		return (NULL);
	if (!get_remain(cur, &len, &str))
		cur->nul = 1;
	if (!cur->nul && cur->l_exist)
		return (get_endl(str, &len, cur));
	while (!cur->nul && read_bufsize(cur, fd) == BUFFER_SIZE && !cur->l_exist)
	{
		str = addstr(str, &len, cur);
		if (str == NULL)
			return (NULL);
	}
	str = get_endl(str, &len, cur);
	if (str == NULL || (!len && !cur->len))
		release(&buflst, cur);
	return (str);
}

char	*addstr(char *prev, int *len, t_buflst *cur)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (*len + cur->len));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < *len)
		str[i] = prev[i];
	free(prev);
	i = -1;
	while (++i < cur->len)
		str[*len + i] = cur->buffer[i];
	*len += i;
	return (str);
}

int	read_bufsize(t_buflst *cur, int fd)
{
	int	i;

	i = 0;
	cur->len = read(fd, cur->buffer, BUFFER_SIZE);
	if (cur->len <= 0)
		return (-1);
	while (i < cur->len)
	{
		if (cur->buffer[i] == '\n')
			cur->l_exist++;
		i++;
	}
	return (cur->len);
}
