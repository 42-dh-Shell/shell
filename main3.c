/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:33:49 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/20 15:22:53 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser/stack/stack.h"
#include "./parser/parser/parser.h"
#include "./parser/stack/stack.h"

int	main()
{
	char *str;

	str = ft_malloc(sizeof(char) * 3);
	str[0] = 'h';
	str[1] = 'a';
	printf("%s\n", str);
}

int	main(int argc, char **argv, char **envp)
{	
	init_shell(envp);

	char	*echo[] = {
		"echo", "123", "1234", "12345", 0
	};
	// char	*cd1[] = {
	// 	"cd", "~"
	// };
	// 	char	*cd2[] = {
	// 	"cd", "../de"
	// };
	// char	*unset[] = {
	// 	"unset", "HOME", 0
	// };
	argv = NULL;
	argc = 0;
	mini_env(echo);	
	mini_export(NULL);
	// mini_unset(unset);
	// printf("%s\n", getcwd(NULL, 0));
	// mini_cd(cd1);
	// printf("%s\n", getcwd(NULL, 0));
	// mini_cd(cd2);
	// printf("%s\n", getcwd(NULL, 0));
// /goinfre/daegulee/builtin
// /Users/daegulee
// minishell : cd : ../de No such file or directory
// /Users/daegulee








	// mini_export(NULL);
	// printf("##########\n");
	// mini_export(export);
	// 	printf("##########\n");

	// mini_export(NULL);
	// mini_cd(cd);
	// mini_pwd(argv);
	// system("leaks mini");
	// start_shell();
}



	// char	*export[] = {
	// 	"export", "132=123", "_1234=123", "a1234", "a12345=123", 0
	// };
	// argc = 0;
	// // if (argc != 1 && argv != NULL)
	// // 	ft_exit("minishell : not support non-interactive mode.\n", 1);
	// init_shell(envp);
	// // argv = NULL;
	// // mini_cd(argv);
	// argv = NULL;
	// mini_export(NULL);
	// 	printf("-------------------------------\n");

	// mini_export(export);
	// 	printf("--------123-----------------------\n");

	// mini_export(NULL);
	// printf("-------------------------------\n");
	// // start_shell();