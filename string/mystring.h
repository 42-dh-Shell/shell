/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystring.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:54:50 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 13:57:31 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSTRING_H
# define MYSTRING_H

# include "../libft/libft.h"

typedef struct s_string
{
	char			*str;
	int				len;
	struct s_string	*next;
}	t_string;

typedef struct s_string_lst
{
	t_string	*head;
	int			lst_len;
}	t_str_lst;

t_str_lst	*init_string_lst(void);
t_string	*init_string(char *str);
void		push_strlst_string(t_str_lst *str_lst, t_string *string);
void		push_string_char(t_string *string, char c);

#endif