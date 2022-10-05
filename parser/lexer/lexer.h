/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:36:54 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/04 14:44:22 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <stdlib.h>
# include "../../libft/libft.h"
# include <stdio.h>
# define ASCII_QUOTE 39
# define ASCII_DQUOTE 34
# define ASCII_EXPAND_SIG 36
# define ASCII_PIPE 124
# define ASCII_GREAT 62
# define ASCII_LESS 60
# define ASCII_AND 38
# define ASCII_LBRAK 40
# define ASCII_RBRAK 41

enum e_types
{
	WORD = 0,
	PIPE,
	AND,
	OR,
	LESS,
	GREAT,
	DLESS,
	DGREAT,
	LBRAC,
	RBRAC,
	LAST
};

typedef struct s_expand_info
{
	char					*str;
	int						start;
	int						size;
	int						split_arg;
	struct s_expand_info	*next;
}	t_expand_info;

typedef struct s_token
{
	char			*str;
	int				wildcard_flag;
	enum e_types	token_type;
	t_expand_info	*expand_info;
	struct s_token	*next;
}	t_token;

void			lexer_parse(char *line);
int				is_space(char c);
int				is_meta(char c);
int				need_stop(char c);
int				is_meta(char c);
int				get_word_len(char **line);
t_expand_info	*allocate_expand_info(void);
t_token			*allocate_token(int word_len);
void			expand_lst_add(t_token *head, t_expand_info *target);
void			token_lst_add(t_token **head, t_token *target);
void			asign_handler(t_token *token, int i);
int				closed_quote_dquote(int i, char **line, char quote_code);
void			division_word(char **line, t_token *token, \
							int *i, int *str_idx);
void			release_token_lst(t_token *head);
t_token			*get_pipe_or_token(char **line);
t_token			*get_great_dgreat_token(char **line);
t_token			*get_less_dless_token(char **line);
t_token			*get_and_token(char **line);
t_token			*get_bracket_toekn(char **line);

#endif