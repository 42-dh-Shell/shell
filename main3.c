#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include "./libft/libft.h"
#include <stdio.h>
#include "./expand/expand.h"

int	foo(void)
{
	char	*wild_str = "*";
	char	**argv;
	int		i;

	i = -1;
	argv = wild_expand(wild_str);
	while (argv[++i])
		printf("%s ", argv[i]);
	printf("\n");
	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
	return (1);
}
// gcc main3.c ./expand/wild_expand.c ./expand/free_queue.c ./expand/wild_expand2.c ./libft/libft.a ./expand/queue_util.c ./builtin/argv_sort.c
// cat *.c *.c d  argv1   
// cat ft_.c ft_a.c ft_b.c c d

// int i
// i = 0;
// while (argv[i])
// { 
//     sub = wild_expand(argv[i]);
//	   argv_change(argv, sub, i);
//	  a
//	   i = i + argv_len(sub);
// }

// origin
// sub 
// 위위치 
int	main()
{
	foo();
	// system("leaks a.out");
	return (0);
}