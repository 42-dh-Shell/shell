/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:07:08 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/14 15:07:22 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# include "../libft/libft.h"
# include <fcntl.h>
# define TMP_FILENAME "tmp"
# define TMP_DIR "/var/folders/zz/zyxvpxvq6csfxvn_n000csj80036c_/T/"

char	*write_line_in_file(char *line, int file_num);
#endif