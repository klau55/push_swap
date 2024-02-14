/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_ops_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:16:31 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/14 13:36:46 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*findby_index(t_node *head, int index)
{
	t_node	*node;

	node = head;
	while (node->index != index && node->next != NULL)
		node = node->next;
	return (node);
}

void	rotate_front(t_node **head)
{
	t_node	*last;

	last = find_back(*head);
	if (*head == NULL || last == *head)
		return ;
	findby_index(*head, len(*head) - 2)->next = NULL;
	last->next = *head;
	*head = last;
	(*head)->index = 0;
	increment_indexes((*head)->next);
}

void	rotate_back(t_node **head)
{
	t_node	*last;
	t_node	*temp;
	int		last_ind;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	last = find_back(*head);
	last_ind = last->index;
	temp->next = NULL;
	last->next = temp;
	decrement_indexes(*head);
	find_back(*head)->index = last_ind;
}

void	pop_front(t_node **head)
{
	t_node	*front;

	if (*head == NULL)
		return ;
	front = *head;
	*head = (*head)->next;
	decrement_indexes(*head);
	free(front);
}

t_node	*back(t_node *node)
{
	while (node && node->next != NULL)
		node = node->next;
	return (node);
}
