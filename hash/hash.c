/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:07:27 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/17 19:50:47 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "../libft/libft.h"

char	*get_hash(t_hash *hash_table, char *key)
{
	unsigned long	hash_val;
	t_hash_list		*tg_list;

	hash_val = hash(key);
	hash_val %= hash_table->table_size;
	tg_list = hash_table->hash_array[hash_val];
	while (tg_list)
	{
		if (ft_strcmp(key, tg_list->key) == 0)
			return (tg_list->value);
		tg_list = tg_list->next;
	}
	return (0);
}

void	resize_start(t_hash_list *tar_array, t_hash_list **new_list, \
										t_hash *hash_table)
{
	unsigned long	hash_val;
	t_hash_list		*new_data;

	while (tar_array)
	{
		hash_val = hash(tar_array->key);
		hash_val %= hash_table->table_size;
		new_data = tar_array;
		new_data->next = 0;
		if (new_list[hash_val] == 0)
			new_list[hash_val] = new_data;
		else
			hash_data_add_back(new_data, new_list[hash_val]);
		tar_array = tar_array->next;
	}
}

void	hash_add(t_hash *hash_table, char *key, char *value)
{
	unsigned long	hash_val;
	t_hash_list		*new_data;
	t_hash_list		**hash_array;

	if (hash_table->load_factor < hash_load_factor(hash_table))
		resize(hash_table);
	hash_val = hash(key);
	hash_val %= hash_table->table_size;
	new_data = get_hash_data(key, value);
	hash_array = hash_table->hash_array;
	if (hash_array[hash_val] == 0)
	{
		hash_array[hash_val] = new_data;
		hash_table->size_elem += 1;
	}
	else
	{
		if (hash_data_add_back(new_data, hash_array[hash_val]))
			hash_table->size_elem += 1;
	}
}

void	hash_remove(t_hash *hash_table, char *key)
{
	unsigned long	hash_val;
	t_hash_list		*target_node;
	t_hash_list		*prev;
	t_hash_list		*next;

	hash_val = hash(key);
	hash_val %= hash_table->table_size;
	target_node = (hash_table->hash_array)[hash_val];
	prev = NULL;
	while (target_node && ft_strcmp(target_node->key, key) != 0)
	{
		prev = target_node;
		target_node = target_node->next;
	}
	if (!target_node)
		return ;
	if (prev == NULL)
		(hash_table->hash_array)[hash_val] = target_node->next;
	else
	{
		next = target_node->next;
		prev->next = next;
	}
	hash_table->size_elem -= 1;
	release_hash_node(target_node);
}
