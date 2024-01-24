#include "push_swap.h"

void	pa(t_node **stack_a, t_node *stack_b)
{
	if (stack_b == NULL)
		return ;
	push_front(stack_a, stack_b->num);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_b, t_node *stack_a)
{
	if (stack_b == NULL)
		return ;
	push_front(stack_b, stack_a->num);
	write(1, "pb\n", 3);
}

void	ra(t_node *stack_a)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	temp = stack_a[0].num;
	while (i < MAX - 1)
	{
		stack_a[i].num = stack_a[i + 1].num;
		i++;
	}
	stack_a[MAX - 1].num = temp;
	printf("ra\n");
}

void	rb(t_node *stack_b)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	temp = stack_b[0].num;
	while (i < MAX - 1)
	{
		stack_b[i].num = stack_b[i + 1].num;
		i++;
	}
	stack_b[MAX - 1].num = temp;
	printf("rb\n");
}
void	rr(t_node *stack_a, t_node *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	printf("rr");
}

void	rra(t_node **head)
{
	t_node	*last;

	last = find_back(*head);
	if (*head == NULL || last == *head)
		return ;
	at_ind(*head, last->index - 1)->next = NULL;
	last->next = *head;

	*head = last;
	(*head)->index = 0;
	increment_indexes((*head)->next);

	printf("rra\n");
}

void	rrb(t_node *stack_b)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	temp = stack_b[MAX - 1].num;
	i = MAX - 1;
	while (i > 0)
	{
		stack_b[i].num = stack_b[i - 1].num;
		i--;
	}
	stack_b[0].num = temp;
	printf("rrb\n");
}

void	rrr(t_node *stack_a, t_node *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	printf("rrr");
}

void	sa(t_node *stack_a)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	temp = stack_a[0].num;
	stack_a[0].num = stack_a[1].num;
	stack_a[1].num = temp;
	printf("sa\n");
}
void	sb(t_node *stack_b)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	temp = stack_b[0].num;
	stack_b[0].num = stack_b[1].num;
	stack_b[1].num = temp;
	printf("sb\n");
}
void ss(t_node *stack_a, t_node *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	printf("ss");
}