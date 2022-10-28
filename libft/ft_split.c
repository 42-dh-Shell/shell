/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:00:27 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/07 20:40:37 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_result_len(char const *s, char c)
{
	int	flag;
	int	idx;
	int	len;

	flag = 1;
	idx = 0;
	len = 0;
	while (s[idx] != 0)
	{
		if (flag && s[idx] != c)
		{
			len++;
			flag = 0;
		}
		else if (s[idx] == c)
			flag = 1;
		idx++;
	}
	return (len);
}

static int	get_strlen(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s != 0 && *s != c)
	{
		s++;
		cnt++;
	}
	return (cnt);
}

static void	release_result(char **result, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
		free(result[i++]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		idx;
	int		str_len;
	int		result_len;

	result_len = get_result_len(s, c);
	result = ft_calloc(result_len + 1, sizeof(char *));
	if (!result)
		return (0);
	idx = 0;
	while (idx < result_len)
	{
		while (*s != 0 && *s == c)
			s++;
		str_len = get_strlen(s, c);
		result[idx] = malloc(sizeof(char) * (str_len + 1));
		if (!result[idx])
		{
			release_result(result, idx);
			return (0);
		}
		ft_strlcpy(result[idx++], s, str_len + 1);
		s += str_len;
	}
	return (result);
}
