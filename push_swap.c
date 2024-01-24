#include "push_swap.h"

int	done_checker(t_node *stack_a)
{
	int	i;

	i = 0;
	while (stack_a[i + 1].num && (i + 1 < MAX))
	{
		if (stack_a[i + 1].num < stack_a[i].num)
			return (1);
		i++;
	}
	return (0);
}

int two(t_node *stack_a)
{
	if (!stack_a[0].num)
		return (-1);
	if (stack_a[0].num > stack_a[1].num)
		sa(stack_a);
	return (0);
}

int	three(t_node **stack)
{
	printf("?%d %d %d \n", (*stack)->num, (*stack)->next->num, back(*stack)->num);
	if ((*stack)->num > (*stack)->next->num \
		&& (*stack)->num > back(*stack)->num)
		ra(*stack);
	if ((*stack)->num > (*stack)->next->num)
		sa(*stack);
	if ((*stack)->next->num > back(*stack)->num)
		rra(*stack);
	if ((*stack)->num > (*stack)->next->num)
		sa(*stack);
	if (done_checker(*stack) == 1)
	{
		printf("*three fails\n");
		return (-1);
	}
	printf("*three exit\n");
	return (0);
	/*
	printf("stack_a[0].num = %d, stack_a[1].num = %d,\
	 stack_a[2].num = %d\n", stack_a[0].num, stack_a[1].num, stack_a[2].num);
	if (!stack_a[0].num)
		return (-1);
	if (stack_a[0].num < stack_a[1].num && stack_a[0].num > stack_a[2].num)
		ra(stack_a);
	if (stack_a[0].num > stack_a[1].num)
		sa(stack_a);
	if (stack_a[1].num > stack_a[2].num)
		rra(stack_a);
	if (stack_a[0].num > stack_a[1].num)
		sa(stack_a);
	if (done_checker(stack_a) == 1)
	{
		printf("*three fails\n");
		return (-1);
	}
	else
	{
		printf("*three done\n");
		return (0);
	}*/
}

int four_to_n(t_node *stack_a, t_node *stack_b)
{
	stack_a = NULL;
	stack_b = NULL;
	return (-1);
}

int main(int argc, char **argv)
{
	int		*arr;
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;
	int		stack_len;
	t_node	*head;

	if (argc < 2)
		return (0);
	if (argc == 2)
		return (printf("%d\n", ft_atoi(argv[1])));
	if (argc < 3 || argc > 4)
		return (printf("no go, only 1 to 3 digits accepted\n"));
	arr = malloc((argc - 1) * sizeof(int));

	if (arr == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (1);
	}
	stack_a = malloc((argc - 1) * sizeof(t_node));
	if (stack_a == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free(arr);
		return (1);
	}
	stack_a = populate_node(argc, argv);
	stack_b = NULL;
	stack_len = len(stack_a);
	head = stack_a;
	printf("===stack_a[0].num = %d, stack_a[1].num = %d,\
	 stack_a[2].num = %d\n", stack_a[0].num, stack_a[1].num, stack_a[2].num);
	while (stack_a->num)
	{
		printf("===%d\n", stack_a->num);
		if (stack_a->next)
			stack_a = stack_a->next;
		else
			break ;
	}
/*
	i = 0;
	while (argv[i + 1] && i < argc - 1)
	{
		if (1 == ft_isdigit((char)argv[i + 1]))
			return (printf("Only digits allowed, why put %s?\n", argv[i + 1]));
		stack_a[i].num = ft_atoi(argv[i + 1]);
		stack_a[i].index = i;
//		printf("*stack number %d num: %d, index: %d\n", i, stack_a[i].num, stack_a[i].index);
		i++;
	}*/
	stack_a = head;
	if (argc == 3)
	{
		if (-1 == two(stack_a))
			return (-1);
	}
	else if (argc == 4)
	{
		printf("*entered if for 3\n");
		if (done_checker(stack_a) == 0)
		{
			printf("no sort needed\n");
		}
		else
			three(&stack_a);
/*		if (-1 == three(stack_a) && printf("aaaaaaaaa") > 0)
		{
			printf("sasasa");
			return (-1);
		}
		else
			printf("ASS"); */
	}
	stack_a = head;
	while (stack_a->num)
	{
		printf("===%d\n", stack_a->num);
		if (stack_a->next)
			stack_a = stack_a->next;
		else
			break ;
	}
	if (argc == 5)
	{
		stack_b = NULL;
		if (-1 == four_to_n(stack_a, stack_b))
			return (-1);
	}
	i = 0;
	stack_a = head;
	while (stack_a)
	{
		printf("out ===%d\n", stack_a->num);
		stack_a = stack_a->next;
	}
	return (0);
}
