/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:07:07 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/10 19:46:59 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb)
{
	unsigned int	i;
	unsigned int	j;

	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	i = 1;
	while (i * i < (unsigned int) nb)
		i++;
	if (i * i == (unsigned int) nb)
		return (0);
	j = 2;
	while (j <= i)
	{
		if ((unsigned int) nb % j == 0)
			return (0);
		j++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb <= 2)
		return (2);
	if (is_prime(nb))
		return (nb);
	i = nb + 1;
	while (is_prime(i) == 0)
	{
		if (is_prime(i))
			break ;
		i++;
	}
	return (i);
}
