/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lalr_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:03:40 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/04 15:03:12 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../get_next_line/get_next_line_bonus.h"
#include "../../libft/libft.h"

char	***allocate_table(void)
{
	char	***result;
	int		i;

	result = malloc (sizeof (char **) * 29);
	if (!result)
		exit(0);
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
		exit(0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		result[i] = ft_split(line, ' ');
		i++;
	}
	close(fd);
	return (result);
}

char	***get_table(void)
{
	static const char	***lalr_table;

	lalr_table = (const char ***) make_table();
	return ((char ***)lalr_table);
}
