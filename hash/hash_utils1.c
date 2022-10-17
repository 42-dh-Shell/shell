/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:27:58 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/17 19:38:49 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	release_hash_node(t_hash_list *target_node)
{
	free(target_node->key);
	free(target_node->value);
	free(target_node);
}

unsigned long	hash(char *str)
{
	unsigned long	hash_val;
	int				c;

	hash_val = 5381;
	while (*str)
	{
		c = (int) *str;
		hash_val = ((hash_val * 33) + hash_val) + c;
		str++;
	}
	return (hash_val);
}

void	resize(t_hash *hash_table)
{
	int			new_size;
	t_hash_list	**new_list;
	int			i;
	int			old_size;

	new_size = ft_find_next_prime(hash_table->table_size * 2);
	new_list = ft_calloc (sizeof (t_hash_list *), new_size);
	if (!new_list)
		ft_exit("malloc error\n", 0);
	i = -1;
	old_size = hash_table->table_size;
	hash_table->table_size = new_size;
	while (++i < old_size)
		resize_start(hash_table->hash_array[i], new_list, hash_table);
	hash_table->hash_array = new_list;
}
