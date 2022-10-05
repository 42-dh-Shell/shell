/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:52:13 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/03 14:38:53 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <sys/types.h>
# include <stdlib.h>

int		ft_strcmp(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str, int *is_overflow);

#endif
