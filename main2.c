#include "./expand/expand.h"

int	wild_check_part(t_queue	*wild_queue, int *i, char *check);

char	look_q_not_asterisk(t_queue *queue)
{
	t_qnode	*cur;

	cur = queue->front;
	while (cur->back && cur->c == '*')
		cur = cur->back;
	if (cur->back == NULL && cur->c == '*')
		return (0);
	return (cur->c);
}

int	is_wild(char *wild_str, char *check)
{
	t_queue	*wild_queue;
	int		i;

	wild_queue = init_str_queue(wild_str);
	i = 0;
	if (!wild_check_part(wild_queue, &i, check))
		return (0);
	if (ft_strlen(&check[i]) == 0 && wild_queue->len == 0)
	{
		free_queue(wild_queue);
		return (1);
	}
	else
	{
		free_queue(wild_queue);
		return (0);
	}
}

int	wild_check_part(t_queue	*wild_queue, int *i, char *check)
{
	while (check[*i] && wild_queue->len)
	{
		if (check[*i] == wild_queue->front->c)
		{
			free(pop_queue(wild_queue));
			(*i)++;
		}
		else
		{
			if (wild_queue->front->c == '*')
			{
				while (check[*i] \
				&& look_q_not_asterisk(wild_queue) != check[*i])
					(*i)++;
				while (wild_queue->len && wild_queue->front->c == '*')
					free(pop_queue(wild_queue));
			}
			else
			{
				free_queue(wild_queue);
				return (0);
			}
		}
	}
	return (1);
}
// gcc main2.c ./libft/libft.a  ./expand/free_queue.c ./expand/queue_util.c
int	main(void)
{
	char	*wild_str = "*a*.c";
	char	*check = "main.c";

	printf("check -> %d\n", is_wild(wild_str, check));
	system("leaks a.out");
}