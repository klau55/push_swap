/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:07:18 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/14 14:17:33 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_values(t_node *a, t_node *b)
{
	int	tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = a->num;
	a->num = b->num;
	b->num = tmp;
}

void	swap_indexes(t_node *a, t_node *b)
{
	int	tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = a->index;
	a->index = b->index;
	b->index = tmp;
}

t_node	*new_node(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = 0;
	new->top_part = true;
	new->cheapest = false;
	new->push_price = 0;
	new->next = NULL;
	return (new);
}

void	increment_indexes(t_node *tail)
{
	while (tail)
	{
		(tail->index)++;
		tail = tail->next;
	}
}

void	decrement_indexes(t_node *tail)
{
	while (tail)
	{
		(tail->index)--;
		tail = tail->next;
	}
}
