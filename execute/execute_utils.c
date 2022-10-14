/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:12:35 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/14 14:48:45 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	*write_line_in_file(char *line, int file_num)
{
	int			fd;
	char		*full_path;

	full_path = ft_calloc (sizeof (char), ft_strlen(TMP_FILENAME) + \
		ft_strlen(TMP_DIR) + ft_strlen(ft_itoa(file_num)) + 1);
	ft_strlcat(full_path, TMP_DIR, ft_strlen(TMP_DIR) + 1);
	ft_strlcat(full_path, TMP_FILENAME, ft_strlen(TMP_FILENAME) + 1);
	ft_strlcat(full_path, ft_itoa(file_num), ft_strlen(ft_itoa(file_num)) + 1);
	fd = open(full_path, O_CREAT, O_WRONLY, 0644);
	if (fd < 0)
		ft_exit("file open failed\n", 1);
	write(fd, line, ft_strlen(line));
	close(fd);
	return (full_path);
}
