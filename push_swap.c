#include "push_swap.h"

int	done_checker(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	two(t_node *stack_a)
{
	if (!stack_a->num)
		return (-1);
	if (stack_a->num > stack_a->next->num)
		sa(&stack_a);
	return (0);
}

int	three(t_node **stack)
{
	if ((*stack)->num > (*stack)->next->num \
		&& (*stack)->num > back(*stack)->num)
		ra(stack);
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
	if ((*stack)->next->num > back(*stack)->num)
		rra(stack);
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
	if (done_checker(*stack) == 1)
	{
		printf("*three fails\n");
		return (-1);
	}
	printf("*three exit sucks ess\n");
	return (0);
}

void	out(t_node *stack_a)
{
	while (stack_a)
	{
		printf("zhopa zhopa OUT: %d INDEX: %d\n", stack_a->num, stack_a->index);
		stack_a = stack_a->next;
	}
}

int main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		stack_len;
	t_node	*head;

	if (argc < 2)
		return (0);
	if (argc == 2)
		return (printf("%d\n", ft_atoi(argv[1])));
	if (argc < 2)
		return (printf("no go\n"));
	stack_a = populate_node(argc, argv);
	stack_b = NULL;
	stack_len = len(stack_a);
	head = stack_a;
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
			printf("no sort needed, exit 3\n");
		}
		else
			three(&stack_a);
	}
	else if (argc > 4)
	{
		stack_b = NULL;
		if (-1 == four_to_n(&stack_a, &stack_b))
			return (-1);
	}
	out(stack_a);
	return (0);
}
