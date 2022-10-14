/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:33:12 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/06 21:55:08 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ch;

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
			return (ch);
		ch++;
	}
	return (0);
}
