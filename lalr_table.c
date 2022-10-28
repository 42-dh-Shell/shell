/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lalr_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:03:40 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/24 21:21:11 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser/parser/parser.h"
#include "./get_next_line/get_next_line_bonus.h"
#include "./libft/libft.h"

char	***allocate_table(void)
{
	char	***result;

	result = malloc (sizeof (char **) * 44);
	if (!result)
		ft_exit("malloc error", 0);
	return (result);
}

char	***make_table(void)
{
	char	*line;
	int		fd;
	char	***result;
	int		i;

	fd = open("parser/parser/table.txt", O_RDONLY);
	result = allocate_table();
	i = 0;
	if (fd < 0)
		ft_exit("file open failed", 0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		result[i] = ft_split(line, '\t');
		i++;
		free(line);
	}
	close(fd);
	return (result);
}
