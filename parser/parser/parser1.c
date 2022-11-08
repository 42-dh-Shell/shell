/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:04:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/07 21:25:12 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../execute/execute.h"
#include "../../signal/signal.h"

int		is_valid_filenum(int file_num)
{
	char		*file_name;
	struct stat	file_info;
	int			result;

	file_name = get_full_filename(file_num);
	result = stat(file_name, &file_info);
	if (result == -1)
		return (1);
	return (0);
}

int	get_file_num(void)
{
	int	file_num;

	file_num = 0;
	while (!is_valid_filenum(file_num))
		file_num++;
	return (file_num);
}