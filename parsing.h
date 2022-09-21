/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:05:53 by idaegyu           #+#    #+#             */
/*   Updated: 2022/09/21 00:00:59 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
// (echo 1  && echo 2) | cat 
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
# define WILD_CARD 12
# define ERROR 13 
# define WORD_SIZE_MAX 255
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

// cmd 1 
// cmd1 | cmd2 
// Data_list -> simple_command
// Data_list -> Data_list pipe		

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
	int		token_num;
	char	token_data[WORD_SIZE_MAX];
}	t_token;

typedef struct s_token_list
{
	t_token	*head;
	t_token	*tail;
	int		len;
}	t_token_list;

#endif