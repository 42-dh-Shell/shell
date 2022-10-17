/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:22:25 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 05:55:41 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

static const char	*g_print_ntype[4] = {
	"NON", "CMD", "CONTROL_OP", "SUBSHELL"
};

static const char	*g_redir_type[4] = {
	"<", "<<", ">", ">>"
};

static const char	*g_cop_type[4] = {
	"Non", "|", " ||",  "&&"
};

void	print_cmd(t_ast_node *cur)
{
	t_cmd		*cmd;
	t_redir		*pre;
	t_redir		*suf;
	t_token		*para;
	t_cmd_name	*name;
	int			i;

	para = NULL;
	suf = NULL;
	pre = NULL;
	cmd = cur->cmd;
	if (cmd->cmd_prefix)
	{
		i = 0;
		if (cmd->cmd_prefix)
			pre = cmd->cmd_prefix->head;
		while (pre && ++i)
		{
			printf("cmd_prefix %d", i);
			printf("%s ", g_redir_type[pre->rd_t]);
			printf("%s ", pre->f_name->token_data);
			pre = pre->next;
		}
		printf("\n");
	}
	if (cmd->cmd_name)
	{
		name = cmd->cmd_name;
		printf("cmd_name %s\n", name->c_name->token_data);
	}
	if (cmd->cmd_suffix)
	{
		if (cmd->cmd_suffix->para_lst)
			para = cmd->cmd_suffix->para_lst->head;
		printf("cmd_suffix ");
		printf("para  : ");
		while (para)
		{
			printf("%s ", para->token_data);
			para = para->next;
		}
		printf("\n");
		i = 0;
		if (cmd->cmd_suffix->pre_rd_lst)
			suf = cmd->cmd_suffix->pre_rd_lst->head;
		while (suf && ++i)
		{
			printf("cmd_suffix %d", i);
			printf("%s ", g_redir_type[suf->rd_t]);
			printf("%s ", suf->f_name->token_data);
			suf = suf->next;
		}
		printf("\n");
	}
}

void	print_cop(t_ast_node *cur)
{
	printf("oprator : %s\n", g_cop_type[cur->control]);
}

void	print_subshell(t_ast_node *cur)
{
	t_ast_node	*cur1;
	t_redir		*cur2;
	int			i;

	cur1 = ((t_ast *)(cur->subshell->subtree))->root;
	printf("subshell ~~~~~~\n");
	cur2 = cur->subshell->sub_rd_lst->head;
	i = 0;
	while (cur2 && ++i)
	{
		printf("subshell redir %d", i);
		printf("%s ", g_redir_type[cur2->rd_t]);
		printf("%s ", cur2->f_name->token_data);
		cur2 = cur2->next;
	}
	do_print(cur1);
	printf("subshell ~~~~~ end\n");
}

void	do_print(t_ast_node *cur)
{
	if (cur == NULL)
		return ;
	do_print(cur->l_child);
	printf("ast_node type ==  %s\n", g_print_ntype[cur->ast_n_type]);
	if (cur->ast_n_type == N_CMD)
		print_cmd(cur);
	if (cur->ast_n_type == N_CONTROL_OP)
		print_cop(cur);
	if (cur->ast_n_type == N_SUBSHELL)
		print_subshell(cur);
	do_print(cur->r_child);
}

// void	do_print(t_ast_node *cur)
// {
// 	print_cmd(cur);
// }

void	print_tree(t_ast *ast)
{
	t_ast_node	*root;

	if (ast == NULL)
		return ;
	root = ast->root;
	do_print(root);
}
