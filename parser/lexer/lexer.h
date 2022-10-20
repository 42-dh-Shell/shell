/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:32:02 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/20 23:26:45 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>
# include <stdio.h>
# include "char_table.h"
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../../libft/libft.h"

typedef struct s_exps
{
	int				start;
	int				end;
	char			*str;
	int				is_quote;
	struct s_exps	*next;
}	t_exps;

typedef struct s_exps_list
{
	t_exps	*head;
}	t_exps_list;

typedef struct s_token
{
	int				token_type;
	char			*token_data;
	int				flag_wild;
	t_exps_list		*exps_list;
	struct s_token	*next;
}	t_token;

typedef struct s_token_list
{
	t_token	*head;
}	t_token_list;

typedef struct s_auto_data
{
	int			prev_state;
	int			next_state;
	char		*str;
	char		*buffer;
	int			buffer_idx;
	int			type;
	int			flag_wild;
	t_exps_list	*exps_list;
}	t_auto_data;

/////////////////////////////

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
# define L_S10 10 // ( state
# define L_S11 11 // & state
# define L_S12 12 // && state
# define L_S13 13 // Error state
# define L_S14 14 // | state
# define L_S15 15 // || state
# define L_S16 16 // is_space state
# define L_S17 17 // finish_state

// Token type 
# define T_WORD 1
# define T_GREATE 5 // >
# define T_DGREATE 6 // >>
# define T_LESS 7 // < 
# define T_DLESS 8 // <<
# define T_R_BRAKIT 9 // )
# define T_L_BRAKIT 10 // (
# define T_AND 12 //&& 
# define T_PIPE 14 // |
# define T_OR 15 // || 
# define T_BOT 18 // $
// auto_exps_utils.c
void			fill_buffer(t_auto_data *data);
int				change_next_state(t_auto_data *data, int state);
int				is_expansion(int c);
void			fill_buffer_exps(t_auto_data *data, t_exps **exps);

/// lexer.c
typedef void	(*t_fp)(t_auto_data *data);
char			get_char_status(int c);
t_token			*last_token(void);
t_token_list	*lexer(char *str);
void			init_auto(t_auto_data **data, char *str);

// list_util.c
void			t_list_addback(t_token_list *t_list, t_token *new);
void			exps_lst_addback(t_exps_list **exps_lst, t_exps *new);
t_token			*init_token(t_auto_data *data);
t_token			*token_dup(t_token *origin);

//do_
void			do_s0(t_auto_data *data);
void			do_s0_v2(t_auto_data *data);
void			do_s1(t_auto_data *data);
void			do_s2(t_auto_data *data);
void			do_s3(t_auto_data *data);
void			do_s4(t_auto_data *data);
void			do_s5(t_auto_data *data);
void			do_s6(t_auto_data *data);
void			do_s7(t_auto_data *data);
void			do_s8(t_auto_data *data);
void			do_s9(t_auto_data *data);
void			do_s10(t_auto_data *data);
void			do_s11(t_auto_data *data);
void			do_s12(t_auto_data *data);
void			do_s13(t_auto_data *data);
void			do_s14(t_auto_data *data);
void			do_s15(t_auto_data *data);
void			do_s16(t_auto_data *data);
void			do_s17(t_auto_data *data);
t_token_list	*lexer(char *str);
void			init_auto(t_auto_data **data, char *str);
t_token			*automata(char **str, int *is_sp);

//
int				ft_strcmp(char *s1, char *s2);
// debug
void			print_type(t_token *token, int i);
void			print_data(t_token *token, int i);
void			print_token(t_token_list *t_list);
void			free_auto(t_auto_data *data);
void			free_t_lst(t_token_list **t_lst);
t_exps			*exps_dup(t_exps *origin);
t_exps_list		*exps_list_dup(t_exps_list *exps_lst);

#endif