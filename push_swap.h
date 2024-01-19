#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define MAX 3

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
}	t_node;

void		sa(t_node *stack_a);
void		sb(t_node *stack_b);
void		ss(t_node *stack_a, t_node *stack_b);
void		pa(t_node **stack_a, t_node *stack_b);
void		pb(t_node **stack_b, t_node *stack_a);
void		ra(t_node *stack_a);
void		rb(t_node *stack_b);
void		rr(t_node *stack_a, t_node *stack_b);
void		rra(t_node *stack_a);
void		rrb(t_node *stack_b);
void		rrr(t_node *stack_a, t_node *stack_b);


void		swap_values(t_node *a, t_node *b);
void		swap_indexes(t_node *a, t_node *b);
t_node		*new_node(int num);
void		free_list(t_node **head);
void		increment_indexes(t_node *tail);
void		decrement_indexes(t_node *tail);
t_node		*find_back(t_node *node);
void		push_front(t_node **head, int num);
void		push_back(t_node *head, int num);
void		rotate_front(t_node **head);



int			done_checker(t_node *stack_a);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			two(t_node *stack_a);
int			three(t_node *stack_a);
int			four_to_n(t_node *stack_a, t_node *stack_b);
int			main(int argc, char **argv);

#endif