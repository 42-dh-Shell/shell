/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:05:53 by idaegyu           #+#    #+#             */
/*   Updated: 2022/09/27 12:57:49 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
// (echo 1  && echo 2) | cat 
// Token Type
# define WORD 1  //max
# define PIPE 2  // | 
# define AND 3	// &&
# define OR 4 	// ||
# define LEFT_BRAKIT 6  // (
# define RIGHT_BRAKIT 7  // )
# define REDIR_LEFT 8	//  ()
# define REDIR_RIGHT 9 
# define REDIR_D_LEFT 10
# define REDIR_D_RIGHT 11
# define ERROR 13 
# define WORD_SIZE_MAX 4096

//
# include "char_table.h"
// libft -
# include "./libft/libft.h"
// Automata For Lex(state)
# define L_S0 0 //init
# define L_S1 1 //Crate_word
# define L_S2 2//Double Quoting 
# define L_S3 3 //Single Quoting
# define L_S4 4 //Expansion state
# define L_S5 5 // > state
# define L_S6 6 // >> state
# define L_S7 7 // < state
# define L_S8 8 // << state
# define L_S9 9 // ) sate 
# define L_S10 10 // ( state)
# define L_S11 11 // & state
# define L_S12 12 // && state
# define L_S13 13 // Error state
# define L_S14 14 // | state
# define L_S15 15 // || state
# define L_S16 16 // is_space state
# define L_S17 17 // finish_state

typedef struct s_exps_info
{
	int					start;
	int					end;
	char				str[WORD_SIZE_MAX];
	struct s_exps_info	*next;
}	t_exps_info;

typedef struct s_auto_data
{
	int			prev_state;
	int			next_state;
	char		*str;
	char		buffer[WORD_SIZE_MAX];
	int			buffer_idx;
	int			type;
	int			flag_wild;
	int			flag_assign;
	t_exps_info	*exps;
}	t_auto_data;

typedef struct s_token_list
{
	t_exps_info	*exps;
}	t_token_list;

typedef struct s_token
{
	int				token_type;
	char			token_data[WORD_SIZE_MAX];
	int				flag_wild;
	int				flag_assign;
	t_exps_info		*exps;
	struct s_token	*next;
}	t_token;

typedef void	(*t_fp)(t_auto_data *data);
typedef struct s_token
{
	int				token_type;
	char			token_data[WORD_SIZE_MAX];
	int				flag_wild;
	int				flag_assign;
	t_exps_info		*exps;
	struct s_token	*next;
}	t_token;

typedef struct s_token_list
{
	t_token	*head;
}	t_token_list;

void	do_s0(t_auto_data *data);
void	do_s1(t_auto_data *data);
int		is_space(char c);
char	get_char_status(int c);
int		is_word(char c);
void	fill_exps_list(t_auto_data *data, t_exps_info *list);
void	init_exps_list(t_auto_data *data, t_exps_info *list);
void	fill_buffer(t_auto_data *data);
int		change_next_state(t_auto_data *data, int state);
void	do_s0(t_auto_data *data);
void	do_s0_v2(t_auto_data *data);
void	do_s1(t_auto_data *data);
void	do_s2(t_auto_data *data);
void	do_s3(t_auto_data *data);
void	do_s4(t_auto_data *data);
void	do_s5(t_auto_data *data);
void	do_s6(t_auto_data *data);
void	do_s7(t_auto_data *data);
void	do_s8(t_auto_data *data);
void	do_s9(t_auto_data *data);
void	do_s10(t_auto_data *data);
void	do_s11(t_auto_data *data);
void	do_s12(t_auto_data *data);
void	do_s13(t_auto_data *data);
void	do_s14(t_auto_data *data);
void	do_s15(t_auto_data *data);
void	do_s16(t_auto_data *data);
void	do_s17(t_auto_data *data);

#endif