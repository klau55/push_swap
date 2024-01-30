#include "push_swap.h"

void	set_position(t_node *stack)
{
	int	i;
	int	center_line;

	if (stack == NULL)
		return ;
	center_line = len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i <= center_line)
			stack->top_part = true;
		else
			stack->top_part = false;
		stack = stack->next;
		i++;
	}
}

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b);
	set_position(*a);
	set_position(*b);
}

static void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b);
	set_position(*a);
	set_position(*b);
}

void	finish_rotation(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->top_part)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->top_part)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

t_node	*return_cheapest(t_node *stack)
{
	t_node	*current_node;

	if (stack == NULL)
		return (NULL);
	current_node = stack;
	while (current_node)
	{
		if (current_node->cheapest)
			return (current_node);
		current_node = current_node->next;
	}
	return (NULL);
}

void	set_cheapest(t_node *b)
{
	long	best_match_value;
	t_node	*best_match_node;

	if (b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	set_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = len(a);
	len_b = len(b);
	while (b)
	{
		b->push_price = b->index;
		if (!(b->top_part))
			b->push_price = len_b - (b->index);
		if (b->target_node->top_part)
			b->push_price += b->target_node->index;
		else
			b->push_price += len_a - (b->target_node->index);
		b = b->next;
	}
}

t_node	*find_smallest(t_node *stack)
{
	long	smallest;
	t_node	*smallest_node;
	t_node	*current_node;

	current_node = stack;
	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (current_node)
	{
		if (current_node->num < smallest)
		{
			smallest = current_node->num;
			smallest_node = current_node;
		}
		current_node = current_node->next;
	}
	return (smallest_node);
}

static void	set_target_node(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_in_a;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num && current_a->num < best_match_index)
			{
				best_match_index = current_a->num;
				target_in_a = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_in_a;
		b = b->next;
	}
}



void	init_nodes(t_node *a, t_node *b)
{
	set_position(a);
	set_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}

static void	move_nodes(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->top_part && cheapest_node->target_node->top_part)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->top_part) && !(cheapest_node->target_node->top_part))
		rev_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

int	four_to_n(t_node **stack_a, t_node **stack_b)
{
	t_node		*smallest;
	int			len_a;

	len_a = len(*stack_a);
	while (len_a-- > 3)
		pb(stack_b, stack_a);
	three(stack_a);
	while (*stack_b)
	{
		init_nodes(*stack_a, *stack_b);
		move_nodes(stack_a, stack_b);
	}
	set_position(*stack_a);
	smallest = find_smallest(*stack_a);
	if (smallest->top_part)
		while (*stack_a != smallest)
			ra(stack_a);
	else
		while (*stack_a != smallest)
			rra(stack_a);
	return (0);
}
