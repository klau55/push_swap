#include "push_swap.h"

int	four_to_n(t_node **stack_a, t_node **stack_b)
{
//	t_node		*smallest;
	int			len_a;

	len_a = len(*stack_a);
	while (len_a-- > 3)
		pb(stack_b, stack_a);
	three(stack_a);
	printf("444444444444444\n");
	return (-1);
}
