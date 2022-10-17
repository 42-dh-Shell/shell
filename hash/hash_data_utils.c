/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:27:58 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/11 10:29:00 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	release_hash_node(t_hash_list *target_node)
{
	free(target_node->key);
	free(target_node->value);
	free(target_node);
}
