/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:40:44 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/06 21:55:42 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	*ch;

	result = 0;
	ch = (char *) s;
	if (c == 0)
	{
		while (*ch != 0)
			ch++;
		return (ch);
	}
	while (*ch != 0)
	{
		if (*ch == (char) c)
			result = ch;
		ch++;
	}
	return (result);
}
