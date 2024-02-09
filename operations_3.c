/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:00:42 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/09 15:01:23 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node *stack_b)
{
	swap_values(stack_b, stack_b->next);
	ft_putstr("sb\n");
}

void	ss(t_node *stack_a, t_node *stack_b)
{
	swap_values(stack_a, stack_a->next);
	swap_values(stack_b, stack_b->next);
	ft_putstr("ss\n");
}
