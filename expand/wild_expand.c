/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 03:55:36 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/20 16:12:59 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include "../body/minishell.h"

extern	t_shell *g_shell;

char	look_q_not_asterisk(t_queue *queue)
{
	t_qnode	*cur;

	cur = queue->front;
	while (cur->back && cur->c == '*')
		cur = cur->back;
	if (cur->back == NULL && cur->c == '*')
		return (0);
	return (cur->c);
}

int	is_wild(char *wild_str, char *check)
{
	t_queue	*wild_queue;
	int		i;

	wild_queue = init_str_queue(wild_str);
	i = 0;
	if (!wild_check_part(wild_queue, &i, check))
		return (0);
	if (ft_strlen(&check[i]) == 0 && wild_queue->len == 0)
	{
		free_queue(wild_queue);
		return (1);
	}
	else
	{
		free_queue(wild_queue);
		return (0);
	}
}

int	wild_check_part(t_queue	*wild_queue, int *i, char *check)
{
	while (check[*i] && wild_queue->len)
	{
		if (check[*i] == wild_queue->front->c)
		{
			free(pop_queue(wild_queue));
			(*i)++;
		}
		else
		{
			if (wild_queue->front->c == '*')
			{
				while (check[*i] \
				&& look_q_not_asterisk(wild_queue) != check[*i])
					(*i)++;
				while (wild_queue->len && wild_queue->front->c == '*')
					free(pop_queue(wild_queue));
			}
			else
			{
				free_queue(wild_queue);
				return (0);
			}
		}
	}
	return (1);
}

int	dir_entry_numb(char	*cur_work_dir)
{
	DIR				*dirp;
	struct dirent	*file;
	int				i;

	dirp = opendir(cur_work_dir);
	i = 0;
	while (1)
	{
		file = readdir(dirp);
		if (!file && errno)
			ft_exit("readdir error\n", 1);
		if (file == NULL)
			break ;
		i++;
	}
	closedir(dirp);
	return (i);
}

char	**wild_expand(char *wild_str)
{
	char			*cur_work_dir_n;
	DIR				*dirp;
	struct dirent	*file;
	char			**argv;
	int				i;

	i = -1;
	cur_work_dir_n = getcwd(NULL, 0);
	argv = ft_malloc(sizeof(char *) * (dir_entry_numb(cur_work_dir_n) + 1));
	dirp = opendir(cur_work_dir_n);
	while (1)
	{
		file = readdir(dirp);
		if (!file && errno)
			ft_exit("readdir error\n", 1);
		if (file == NULL)
			break ;
		if ((file->d_name)[0] != '.' && is_wild(wild_str, file->d_name))
			argv[++i] = ft_strdup(file->d_name);
	}
	wild_expand_finish(argv, ++i, wild_str, cur_work_dir_n);
	argv_sort(argv);
	closedir(dirp);
	return (argv);
}
