/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:08:32 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/27 22:03:08 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_exit(const char *str, int exit_flag)
{
	if (str)
	{
		ft_putstr_fd("\033[31mError : ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\033[0m", 2);
	}
	else
		perror("bash");
	exit(exit_flag);
}

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memset(void *b, int c, int len)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)b;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	if (SIZE_MAX - 8192 > (unsigned long)ft_strlen(s1))
		str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	else
		return (NULL);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
