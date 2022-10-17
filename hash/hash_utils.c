/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:40:48 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/17 19:41:21 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "../libft/libft.h"

t_hash	*make_hash_table(int size, double load_factor)
{
	t_hash		*new_hash;
	t_hash_list	**hash_list_head;
	int			table_size;

	new_hash = ft_calloc(sizeof(t_hash), 1);
	if (!new_hash)
		ft_exit("malloc error\n", 0);
	table_size = ft_find_next_prime(size);
	hash_list_head = ft_calloc(sizeof(t_hash_list *), table_size);
	if (!hash_list_head)
		ft_exit("malloc error\n", 0);
	new_hash->table_size = table_size;
	new_hash->load_factor = load_factor;
	new_hash->hash_array = hash_list_head;
	return (new_hash);
}

t_hash_list	*get_hash_data(char *key, char *value)
{
	t_hash_list	*data;

	data = ft_calloc(sizeof(t_hash_list), 1);
	if (!data)
		ft_exit("malloc error\n", 0);
	data->key = key;
	data->value = value;
	return (data);
}

int	same_key_handler(t_hash_list *data, t_hash_list *list)
{
	char	*tmp;

	if (ft_strcmp(list->key, data->key) == 0)
	{
		tmp = list->value;
		list->value = data->value;
		free(tmp);
		free(data->key);
		free(data);
		return (1);
	}
	return (0);
}

void	hash_data_add_back(t_hash_list *data, t_hash_list *list, \
	t_hash *hash_table)
{
	t_hash_list	*prev;

	prev = NULL;
	while (list->next)
	{
		if (same_key_handler(data, list))
			return ;
		prev = list;
		list = list->next;
	}
	if (prev == NULL)
	{
		if (same_key_handler(data, list))
			return ;
	}
	list->next = data;
	hash_table->size_elem += 1;
}

double	hash_load_factor(t_hash *hash)
{
	int			cnt;
	int			i;
	t_hash_list	**hash_list;

	i = 0;
	cnt = 0;
	hash_list = hash->hash_array;
	while (i < hash->table_size)
	{
		if (hash_list[i] != 0)
			cnt++;
		i++;
	}
	return (cnt / (double) hash->table_size);
}
