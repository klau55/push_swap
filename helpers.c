/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:07:12 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/03 14:37:22 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str, t_node *head)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f' \
		|| str[i] == '\t' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			num = num * 10 + (str[i] - '0');
		else
			handle_error(&head, NULL);
		i++;
	}
	return (num * neg);
}

int	repetition(t_node *stack, long int nb)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->num == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_node	*populate_node(char **argv)
{
	t_node		*head;
	long int	nb;
	int			i;

	head = NULL;
	nb = 0;
	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (NULL);
		nb = ft_atoi(argv[i], head);
		if (nb > INT_MAX || nb < INT_MIN)
			return (NULL);
		if (repetition(head, nb) == 1)
			return (NULL);
		if (i == 0)
			head = new_node((int)nb);
		else
			push_back(head, (int)nb);
		i++;
	}
	//set_indexes(head);
	return (head);
}
