/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:48:44 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/05 20:12:16 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_cnt(const char *src, char sep)
{
	size_t	numb;

	numb = 0;
	while (*src)
	{
		if (!(*src == sep || *src == 0)
			&& (*(src + 1) == sep || *(src + 1) == 0))
			numb ++;
		src++;
	}
	return (numb);
}

void	free_split(char **split)
{	
	int	i;

	i = 0;
	while (split[i])
		i++;
	while (i--)
		free(split[i]);
	free(split);
}

static void	create_split(char **split, const char *src, char sep)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*src)
	{
		len = 0;
		if (*src == sep)
			src++;
		else
		{
			while (!(*src == sep || *(src) == 0) && src++)
				len++;
			split[i] = (char *)malloc(sizeof(char) * (len + 1));
			if (split[i] == NULL)
				ft_exit("malloc error.\n", 1);
			ft_strlcpy(split[i], (src - len), len + 1);
			i++;
		}
	}
	split[i] = NULL;
	return (1);
}

char	**ft_split(const char *src, char sep)
{
	size_t	n_word;
	char	**split;

	if (src == NULL)
		return (NULL);
	n_word = word_cnt(src, sep);
	split = (char **)malloc(sizeof(char *) * (n_word + 1));
	if (split == NULL)
		ft_exit("malloc error.\n", 1);
	create_split(split, src, sep);
	return (split);
}
