/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_expand3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:26:37 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/28 17:30:36 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	get_expd_str_help(char *str, t_expand_info *expand_info, \
char *value, int i)
{
	expand_info->start = ft_strlen(str);
	expand_info->size = ft_strlen(value);
	ft_strlcat (str + ft_strlen(str), value, ft_strlen(str) + \
	ft_strlen(value) + 1);
	i += ft_strlen(value);
}
