/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:19:38 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/17 19:35:04 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	**reallocate_result(int size, char **strs)
{
	char	**result;

	result = ft_calloc(sizeof(char *), size);
	if (!result)
		ft_exit("malloc error\n", 1);
	if (strs == NULL)
		return (result);
}
