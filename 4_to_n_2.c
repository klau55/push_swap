/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_to_n_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:11:57 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/14 14:39:11 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
