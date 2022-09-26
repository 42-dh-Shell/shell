/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:01:05 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/26 16:05:05 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	get_char_status(int c)
{
	return (g_char_table[(unsigned char)c]);
}

int	is_word(char c)
{
	return (get_char_status(c) == WORD);
}
