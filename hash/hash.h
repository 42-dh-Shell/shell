/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:07:34 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/11 10:29:14 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H
# include <stdlib.h>

typedef struct s_hash_list
{
	char				*key;
	char				*value;
	struct s_hash_list	*next;
}	t_hash_list;

typedef struct s_hash
{
	int			num_elems;
	int			table_size;
	double		load_factor;
	t_hash_list	**hash_array;
}	t_hash;

t_hash			*get_hash(int table_size, double load_factor);
t_hash_list		*get_hash_data(char *key, char *value);
void			hash_data_add_back(t_hash_list *data, t_hash_list **list);
double			hash_load_factor(t_hash *hash);
void			hash_add(t_hash *hash_table, char *key, char *value);
void			hash_remove(t_hash *hash_table, char *key);
t_hash_list		*hash_get(t_hash *hash_table, char *key);
unsigned long	hash(char *str);
int				ft_find_next_prime(int nb);
void			release_hash_node(t_hash_list *target_node);
#endif
