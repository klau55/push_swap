/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:07:22 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/09 15:00:34 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (stack_b == NULL)
		return ;
	push_front(stack_a, (*stack_b)->num);
	pop_front(stack_b);
	ft_putstr("pa\n");
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	if (stack_a == NULL)
		return ;
	push_front(stack_b, (*stack_a)->num);
	pop_front(stack_a);
	ft_putstr("pb\n");
}

void	ra(t_node **stack_a)
{
	rotate_back(stack_a);
	ft_putstr("ra\n");
}

void	rb(t_node **stack_b)
{
	rotate_back(stack_b);
	ft_putstr("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate_back(stack_a);
	rotate_back(stack_b);
	ft_putstr("rr\n");
}
