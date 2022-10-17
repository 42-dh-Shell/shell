/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:27:58 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/17 13:50:25 by hyunkyle         ###   ########.fr       */
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

// t_hast_list	*get_target_node(t_hash_list *target_node, \
// 	)
// {
	
// }
