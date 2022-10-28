/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:53:11 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/09/30 19:19:03 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"

void	release_node(t_file **head, t_file *file_node)
{
	t_file	*cur;
	t_file	*prev;

	cur = *head;
	prev = 0;
	while (cur != file_node)
	{
		prev = cur;
		cur = cur->next;
	}
	if (prev == 0)
		*head = (*head)->next;
	else
		prev->next = cur->next;
	free(file_node);
}

int	read_file(t_file *file_node, t_file **head)
{
	int		cnt;
	char	*str;
	int		idx;

	file_node->size = read (file_node->fd, file_node->buffer, BUFFER_SIZE);
	if (file_node->size <= 0)
	{
		release_node(head, file_node);
		return (0);
	}
	cnt = 0;
	idx = 0;
	str = file_node->buffer;
	while (idx < file_node->size)
	{
		if (str[idx] == '\n')
			cnt++;
		idx++;
	}
	file_node->cnt_newline = cnt;
	return (file_node->size);
}

char	*make_result(t_file *file_node, char *str, int s_len)
{
	int		len;
	char	*result;

	len = 0;
	while (file_node->buffer[len] != '\n')
		len++;
	if (str == 0)
	{
		result = malloc (sizeof(char) * (len + 2));
		ft_strlcpy_gnl(result, file_node->buffer, len + 2);
	}
	else
	{
		while (str[s_len] != 0)
			s_len++;
		result = malloc(sizeof(char) * (s_len + file_node->size + 1));
		ft_strlcpy_gnl(result, str, s_len + 1);
		ft_cat_str(result, file_node->buffer, s_len + len + 1);
		free(str);
	}
	ft_substr_gnl(file_node->buffer, len + 1, file_node->size - len - 1,
		file_node->size);
	file_node->cnt_newline = file_node->cnt_newline - 1;
	file_node->size = file_node->size - len - 1;
	return (result);
}

char	*start_read(t_file *file_node, int rd_size, t_file **head)
{
	char	*str;

	str = 0;
	while (1)
	{
		if (file_node->size == 0)
		{
			rd_size = read_file(file_node, head);
			if (rd_size == 0)
				return (str);
		}
		else if (file_node->size > 0)
		{
			if (file_node->cnt_newline > 0)
				return (make_result(file_node, str, 0));
			else
			{
				str = fill_str(file_node, str);
				rd_size = read_file(file_node, head);
				if (rd_size == 0)
					return (str);
			}
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_file	*head = 0;
	t_file			*file_node;
	t_file			*tmp;

	if (!head)
		head = ft_lstnew(fd);
	file_node = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp->fd == fd)
			file_node = tmp;
		tmp = tmp->next;
	}
	if (file_node == 0)
	{
		file_node = ft_lstnew(fd);
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = file_node;
	}
	return (start_read(file_node, 0, &head));
}
