#ifndef STUDY_H
# define STUDY_H

# define IF 32
# define WORD 10
# define space 15
# define GRATER 13
# define WORD_COMMAND 12 
# define equal 14
# define semicolon 20
# define NUMBER 1
# define brakit_left 11 
# define brakit_right 9
// 				cat 
// Token num 	10
//	Token val 	"cat"
// "if"
// if (token num = IF)
	// do_right;
//  if (ft_strcmp(token_num , "if"))
	// do_right; 
// if (32 == COMM_NUM)
	// execuve(tokenval);
// 
// 				if  ( a > 3 )  a = 3;
// Token num :  32 15 11 15 10 15 GRATER NUMBER  space brakit_right space id equal sp  num semicolon
// Token val :  0  0   0  0 "ascii=a" 0 0 3      0     0
//   if   else
// S -> B ->  C
//   	 	then
// 	   -> D
// 32->  IF -automata !. 
// Start -> 
// brakit_left 받기 전까지  state를 안넘어감  brakit_left -> s1 .- Condition
// conditon -> Expr  
// s1 - brakit_right  ->s2 -> THEN
// THEN -> statement 
// statemeent  semicolon 이 와야 멈출 수 있음 ..
// statement -> EXPR * semicolon  
// ELSE없으면 실행 .
// automata소환 
// IFCOND -> THEN | ELSE
// Then -> Statement 
// ELSE -> epslion | Statement 
// statement - > Command
// 				IF
//			GRATER					SUBSTITUTE
//	WORD_ID = a   NUM = 3     WORD_ID = a	 NUM 3;

// 			IF 
// cat | g
#endif