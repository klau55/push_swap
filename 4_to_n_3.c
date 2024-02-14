/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_to_n_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:12:00 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/14 14:37:24 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes(t_node *a, t_node *b)
{
	set_position(a);
	set_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}

void	move_nodes(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->top_part && cheapest_node->target_node->top_part)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->top_part) && \
	!(cheapest_node->target_node->top_part))
		rev_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
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

void	set_target_node(t_node *a, t_node *b)
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
