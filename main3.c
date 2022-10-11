/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:33:49 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/11 02:07:50 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser/stack/stack.h"
#include "./parser/parser/parser.h"
#include "./parser/stack/stack.h"

int	main()
{
	char *str;

	str = ft_malloc(sizeof(char) * 3);
	str[0] = 'h';
	str[1] = 'a';
	printf("%s\n", str);
}
