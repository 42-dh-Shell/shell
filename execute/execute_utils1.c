/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:49:03 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/20 19:14:09 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	*get_full_path(char *path, char *comm)
{
	int		p_len;
	int		c_len;
	char	*full_path;

	p_len = ft_strlen(path);
	c_len = ft_strlen(comm);
	full_path = ft_calloc(sizeof(char), (p_len + c_len + 2));
	if (!full_path)
		ft_exit("malloc error\n", 1);
	ft_strlcat(full_path, path, p_len + 1);
	full_path[p_len] = '/';
	ft_strlcat(full_path, comm, p_len + c_len + 2);
	return (full_path);
}

int	is_valid_command(char *command)
{
	struct stat	file_info;
	int			result;

	result = stat(command, &file_info);
	if (result == -1)
		return (0);
	return (1);
}

char	*get_valid_fullpath(char **paths, char **argv)
{
	int		i;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		full_path = get_full_path(paths[i], argv[0]);
		if (is_valid_command(full_path))
			return (full_path);
		i++;
	}
	return (NULL);
}

void	envp_join(char **argv, int j, char *key, char *value)
{
	char	*tmp;

	tmp = ft_strjoin(key, "=");
	argv[j] = ft_strjoin(tmp, value);
	free(tmp);
}

char	**get_envp(void)
{
	t_hash_list	*cur;
	int			i;
	char		**argv;
	int			j;

	j = -1;
	argv = ft_malloc(sizeof(char *) * (g_shell->h_table->size_elem + 1));
	i = -1;
	while (++i < g_shell->h_table->table_size)
	{
		cur = g_shell->h_table->hash_array[i];
		while (cur)
		{
			if (ft_strcmp(cur->value, "") == 0)
			{
				cur = cur->next;
				continue ;
			}
			envp_join(argv, ++j, cur->key, cur->value);
			cur = cur->next;
		}
	}
	argv[++j] = NULL;
	return (argv);
}
