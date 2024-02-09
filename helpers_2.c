/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:58:39 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/09 15:31:02 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*populate_node(char **argv, int flag, long int nb, int i)
{
	t_node		*head;

	head = NULL;
	while (argv[i])
	{
		if ((argv[i][0] == '\0') || (error_syntax(argv[i])))
		{
			if (flag == 1)
				free(*argv);
			handle_error(&head, NULL);
		}
		nb = ft_atoi(argv[i], head);
		if ((nb > INT_MAX || nb < INT_MIN) || (repetition(head, nb) == 1))
		{
			if (flag == 1)
				free(*argv);
			handle_error(&head, NULL);
		}
		if (i++ == 0)
			head = new_node((int)nb);
		else
			push_back(head, (int)nb);
	}
	return (head);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_free(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}
