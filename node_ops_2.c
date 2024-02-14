/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_ops_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:16:27 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/14 13:36:53 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*at_ind(t_node *head, int index)
{
	t_node	*node;

	node = head;
	while (node->index != index && node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

t_node	*find_back(t_node *node)
{
	while (node && node->next)
		node = node->next;
	return (node);
}

void	push_front(t_node **head, int num)
{
	t_node	*new;

	new = new_node(num);
	if (head || new)
		new->next = *head;
	*head = new;
	increment_indexes(new->next);
}

void	push_back(t_node *head, int num)
{
	t_node	*prev;
	t_node	*curr;

	prev = find_back(head);
	curr = new_node(num);
	if (prev == NULL || curr == NULL)
		return ;
	curr->next = prev->next;
	prev->next = curr;
	curr->index = prev->index;
	increment_indexes(prev->next);
}

int	distance(t_node *first, t_node *last)
{
	int	res;

	res = 0;
	while (first && first != last)
	{
		res++;
		first = first->next;
	}
	return (res);
}
