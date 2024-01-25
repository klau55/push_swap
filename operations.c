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

void	ra(t_node **stack_a)
{
	rotate_back(stack_a);
	printf("ra\n");
}

void	rb(t_node **stack_b)
{
	rotate_back(stack_b);
	printf("rb\n");
}
void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate_back(stack_a);
	rotate_back(stack_b);
	printf("rr");
}

void	rra(t_node **stack_a)
{
	rotate_front(stack_a);
	printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	rotate_front(stack_b);
	printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rotate_front(stack_a);
	rotate_front(stack_b);
	printf("rrr");
}

void	sa(t_node *stack_a)
{
	swap_values(stack_a, stack_a->next);
	swap_indexes(stack_a, stack_a->next);
	printf("sa\n");
}
void	sb(t_node *stack_b)
{
	swap_values(stack_b, stack_b->next);
	swap_indexes(stack_b, stack_b->next);
	printf("sb\n");
}
void ss(t_node *stack_a, t_node *stack_b)
{
	swap_values(stack_a, stack_a->next);
	swap_indexes(stack_a, stack_a->next);
	swap_values(stack_b, stack_b->next);
	swap_indexes(stack_b, stack_b->next);
	printf("ss");
}