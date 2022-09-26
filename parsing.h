/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:05:53 by idaegyu           #+#    #+#             */
/*   Updated: 2022/09/26 15:45:32 by daegulee         ###   ########.fr       */
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

// libft -
# include "./libft/libft.h"
// Automata For Lex(state)
# define L_S0 0 //init
# define L_S1 1 //Crate_word
# define L_S2 2//Double Quoting 
# define L_S3 3 //Single Quoting
# define L_S4 4 //I state
# define L_S5 5 //Pipe state
# define L_S6 6 //OR state
# define L_S7 7 //& state
# define L_S8 8 //ANd state
# define L_S9 9 //Error 
# define L_S10 10 //left_brace
# define L_S11 11 //right_brace
# define L_S12 12 // finish
# define L_S13 13 // white_space
# define L_S14 14 // < redir_left
# define L_S15 15 // > redir_right
# define L_S16 16 // << redir_double_left
# define L_S17 17 // >> redir_double_right

typedef struct s_auto_data
{
	int		state;
	char	*str;
	char	buffer[WORD_SIZE_MAX];
	int		buffer_idx;
	int		type;
}	t_auto_data;

int		is_alpha_digit(char c);
void	do_s0(t_auto_data *data);
void	do_s1(t_auto_data *data);
int		is_space(char c);

typedef void	(*t_fp)(t_auto_data *data);

// cat <a | grep 123 | ls -al $h 

//   WO
//
//S -> Data_list
// 
// simple_command -> command_elem
// simple_command -> simple_command command_elem

// command_elem -> redir 
// command_elem -> 'word'

// redir -> 'redir_left(<)' redir_word
// redir -> 'redir_right(>)' redir_word
// redir -> 'redir_d_left(<<)' redir_word
// redir -> 'redir_d_right(>>)' redir_word
// redir_word -> 'word'
// pipe -> 'PIPE' simple_command
// pipe -> pipe 'PIPE' simple_command 

// or -> 'OR' simple_command
// or -> or 'OR' simple_command

// and -> 'and' simple_command 
// and -> and 'and' simple_command

// cmd 1 
// cmd1 | cmd2 
// Data_list -> simple_command
// Data_list -> Data_list pipe		
// Data_list -> Data_list and
// Data_list -. Data_list or
// 
												//Data_list
																	//Data_list
										//simple_command 					pipe								pipe
// 							simple_command 						PIPE										
//      simple_command  command_elem			command elem 					simple_command						
//state (No comd)  		(cmd)		
//											redir					simple_command	command_elem		PIPE				simple_command	
																		

// 			
																									//DATA_list
																		//DATA_list
															//Data_list
								//simple_command						
//				simple_command												pipe										pipe
//		command_elem	command_elem		command_elem						simple_command								simple_command
//state	 (NO comd)		(cmd)				redir						command_elem	command_elem 				Command_elem	command_elem									command_elem 	command_elem	command_elem	
//       word 			word			redir_left word			   PIPE	word			word	       		PIPE   	word   			word 			
//       cat      filename      			  <a                   |    grep   			 123                |         ls  		 -al 				 		

																		//AST
								//cmd							
															// 			PIPE 						
								//			redir_data						cmd									cmd
//			cat		filename    									grep		123							ls		-al

// 			main
//	cat			grep
// <	X	 X		123
//a 
// && || - > and or 
//Token num// word redir_left r_file   pipe  word word pipe word  word Word
//Token data// cat  0			a	     0	grep  123   0	ls  -al  $h
// tokendata char[WORD_SIZE_MAX];  
//  word val * $ ->expand
// 	token val $ ->expand
typedef struct s_token
{
	int		token_type;
	char	token_data[WORD_SIZE_MAX];
}	t_token;

typedef struct s_token_list
{
	t_token	*head;
	t_token	*tail;
	int		len;
}	t_token_list;

#endif