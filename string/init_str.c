/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:56:39 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 13:57:36 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mystring.h"

t_str_lst	*init_string_lst(void)
{
	t_str_lst	*str_lst;

	str_lst = ft_malloc(sizeof(t_str_lst));
	return (str_lst);
}

t_string	*init_string(char *str)
{
	t_string	*string;

	string = ft_malloc(sizeof(t_string));
	string->str = str;
	return (string);
}

void	push_strlst_string(t_str_lst *str_lst, t_string *string)
{
	t_string	*cur;

	cur = str_lst->head;
	if (cur == NULL)
	{
		str_lst->head = string;
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = string;
	(str_lst->lst_len)++;
}
