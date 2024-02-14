/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_ops_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:18:29 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/14 13:20:53 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len(t_node *head)
{
	if (!head)
		return (0);
	return (distance(head, back(head)) + 1);
}

void	set_indexes(t_node *head)
{
	t_node	*node;
	int		i;

	i = 0;
	node = head;
	while (node)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}
