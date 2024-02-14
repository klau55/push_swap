/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:59:58 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/14 14:39:29 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				num;
	int				index;
	bool			top_part;
	bool			cheapest;
	struct s_node	*target_node;
	int				push_price;
	struct s_node	*next;
}	t_node;

// node_ops.c
void		swap_values(t_node *a, t_node *b);
void		swap_indexes(t_node *a, t_node *b);
t_node		*new_node(int num);
void		increment_indexes(t_node *tail);
void		decrement_indexes(t_node *tail);

// node_ops_2.c
t_node		*at_ind(t_node *head, int index);
t_node		*find_back(t_node *node);
void		push_front(t_node **head, int num);
void		push_back(t_node *head, int num);
int			distance(t_node *first, t_node *last);

// node_ops_3.c
t_node		*findby_index(t_node *head, int index);
void		rotate_front(t_node **head);
void		rotate_back(t_node **head);
void		pop_front(t_node **head);
t_node		*back(t_node *node);

// node_ops_4.c
int			len(t_node *head);
void		set_indexes(t_node *head);

// operations.c
void		pa(t_node **stack_a, t_node **stack_b);
void		pb(t_node **stack_b, t_node **stack_a);
void		ra(t_node **stack_a);
void		rb(t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);

// operations_2.c
void		rra(t_node **stack_a);
void		rrb(t_node **stack_b);
void		rrr(t_node **stack_a, t_node **stack_b);
void		sa(t_node **stack_a);

// operations_3.c
void		sb(t_node *stack_b);
void		ss(t_node *stack_a, t_node *stack_b);

// helpers.c
int			ft_isdigit(int c);
long	int		ft_atoi(const char *str, t_node *head);
int			repetition(t_node *stack, long int nb);
int			error_syntax(char *str_nbr);

// helpers_2.c
t_node		*populate_node(char **argv, int flag, long int nb, int i);
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_free(char **argv);

// ft_split.c
char		**ft_split(char *s, char c);

// error_handling.c
void		free_stack(t_node **stack);
void		free_list(t_node **head);
void		handle_error(t_node **stack_a, t_node **stack_b);

// 4_to_n.c
void		set_position(t_node *stack);
void		rotate_both(t_node **a, t_node **b, t_node *cheapest_node);
void		rev_rotate_both(t_node **a, t_node **b, \
	t_node *cheapest_node);
void		finish_rotation(t_node **stack, t_node *top_node, char stack_name);
int			four_to_n(t_node **stack_a, t_node **stack_b);

// 4_to_n_2.c
void		set_cheapest(t_node *b);
void		set_price(t_node *a, t_node *b);
t_node		*find_smallest(t_node *stack);

// 4_to_n_3.c
void		init_nodes(t_node *a, t_node *b);
void		move_nodes(t_node **a, t_node **b);
t_node		*return_cheapest(t_node *stack);
void		set_target_node(t_node *a, t_node *b);

// push_swap.c
int			done_checker(t_node *stack);
int			two(t_node *stack_a);
int			three(t_node **stack);
void		process_stacks(t_node *a, t_node *b, int flag, char **argv);
int			main(int argc, char **argv);

#endif