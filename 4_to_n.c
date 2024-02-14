/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_to_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:07:02 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/14 14:37:38 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b);
	set_position(*a);
	set_position(*b);
}

void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
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
