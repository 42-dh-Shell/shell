#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include "./libft/libft.h"
#include <stdio.h>
#include "./expand/expand.h"

int	foo(void)
{
	char	*wild_str = "*a*.c";
	char	**argv;
	int		i;

	i = -1;
	argv = wild_expand(wild_str);
	while (argv[++i])
		printf("argv[%d] = %s\n", i, argv[i]);
	return (1);
}
// gcc main3.c ./expand/wild_expand.c ./expand/free_queue.c ./expand/wild_expand2.c ./libft/libft.a ./expand/queue_util.c
int	main()
{
	foo();
	// system("leaks a.out");
	return (0);
}