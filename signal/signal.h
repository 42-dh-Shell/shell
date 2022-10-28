/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:41:38 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/28 16:20:03 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H
# include "../libft/libft.h"

void	signal_handler(int signum);
void	print_exit(void);
void	set_signal_term(void);
void	signal_here_doc(int signum);

#endif
