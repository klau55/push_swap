/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:59:16 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/09 15:01:54 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack_a)
{
	rotate_front(stack_a);
	ft_putstr("rra\n");
}

void	rrb(t_node **stack_b)
{
	rotate_front(stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rotate_front(stack_a);
	rotate_front(stack_b);
	ft_putstr("rrr\n");
}

void	sa(t_node **stack_a)
{
	swap_values(*stack_a, (*stack_a)->next);
	ft_putstr("sa\n");
}
