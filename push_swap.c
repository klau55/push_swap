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

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (printf("no go\n"));
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
	}
	else
		argv = argv + 1;
	stack_a = populate_node(argv);
	stack_b = NULL;
	stack_len = len(stack_a);
	head = stack_a;
	if (stack_len == 1)
		return (printf("OUT: %d INDEX: 0\n", stack_a->num));
	else if (stack_len == 3 || stack_len == 2)
	{
		printf("*entered if for 2/3\n");
		if (done_checker(stack_a) == 0)
		{
			printf("no sort needed, exit 3\n");
		}
		else
			three(&stack_a);
	}
	else if (stack_len > 4)
	{
		if (-1 == four_to_n(&stack_a, &stack_b))
			return (-1);
	}
	out(stack_a);
	//TODO: free stack
	return (0);
}
