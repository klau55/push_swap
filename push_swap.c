/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:07:27 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/09 16:31:14 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	done_checker(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	two(t_node *stack_a)
{
	if (!stack_a->num)
		return (-1);
	if (stack_a->num > stack_a->next->num)
		sa(&stack_a);
	return (0);
}

int	three(t_node **stack)
{
	if ((*stack)->num > (*stack)->next->num \
		&& (*stack)->num > back(*stack)->num)
		ra(stack);
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
	if ((*stack)->next->num > back(*stack)->num)
		rra(stack);
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
	if (done_checker(*stack) == 1)
	{
		handle_error(stack, NULL);
		return (-1);
	}
	return (0);
}


void	process_stacks(t_node *stack_a, t_node *stack_b, int flag, char **argv)
{
	int	stack_len;

	stack_a = populate_node(argv, flag, 0, 0);
	if (stack_a == NULL)
		handle_error(&stack_a, &stack_b);
	stack_len = len(stack_a);
	if (done_checker(stack_a) != 0)
	{
		if (stack_len <= 3)
		{
			if (-1 == three(&stack_a))
				handle_error(&stack_a, &stack_b);
		}
		else if (stack_len > 3)
		{
			if (-1 == four_to_n(&stack_a, &stack_b))
				handle_error(&stack_a, &stack_b);
		}
	}
	if (flag == 1)
		ft_free(argv);
	free_list(&stack_a);
	free_list(&stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		flag;

	flag = 0;
	if (argc < 2 || (argc == 2 && !argv[1][0]) || argv[argc - 1][0] == '\0')
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');

		if (argv == NULL)
			handle_error(&stack_a, &stack_b);

		flag = 1;
	}
	else
		argv = argv + 1;
	process_stacks(stack_a, stack_b, flag, argv);

	return (0);
}
