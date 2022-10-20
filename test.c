S -> Data_list

Data_list -> SIMPLE_COMMAND
Data_list -> Data_list PIPE	
Data_list -> Data_list AND
Data_list -> Data_list OR

SIMPLE_COMMAND -> COMMAND_ELEM
SIMPLE_COMMAND -> SIMPLE_COMMAND COMMAND_ELEM
SIMPLE_COMMAND -> SUBSHELL
SUBSHELL -> '(' Data_list ')'

COMMAND_ELEM -> REDIR
COMMAND_ELEM -> WORD

REDIR -> '<' REDIR_WORD
REDIR -> '>' REDIR_WORD
REDIR -> '<<' REDIR_WORD
REDIR -> '>>' REDIR_WORD
REDIR_WORD -> 'word'

PIPE -> '|' SIMPLE_COMMAND
PIPE -> PIPE '|' SIMPLE_COMMAND

OR -> '||' SIMPLE_COMMAND
OR -> OR '||' SIMPLE_COMMAND

AND -> '&&' SIMPLE_COMMAND
AND -> AND '&&' SIMPLE_COMMAND


//tokenizing - > parser  - > expand -> execute

// redir 병렬 
// heredoc 직렬 