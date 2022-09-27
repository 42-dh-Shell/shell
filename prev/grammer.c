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