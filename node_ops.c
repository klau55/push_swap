# include "push_swap.h"

void	swap_values(t_node *a, t_node *b)
{
	int	tmp;

	tmp = a->num;
	a->num = b->num;
	b->num = tmp;
}

void	swap_indexes(t_node *a, t_node *b)
{
	int	tmp;

	tmp = a->index;
	a->index = b->index;
	b->index = tmp;
}

t_node	*new_node(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	free_list(t_node **head)
{
	t_node	*tmp;

	if (!head || !(*head))
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}

void	increment_indexes(t_node *tail)
{
	while (tail)
	{
		(tail->index)++;
		tail = tail->next;
	}
}

void	decrement_indexes(t_node *tail)
{
	while (tail)
	{
		(tail->index)++;
		tail = tail->next;
	}
}

t_node	*find_back(t_node *node)
{
	while (node && node->next)
		node = node->next;
	return (node);
}

void	push_front(t_node **head, int num)
{
	t_node	*new;

	new = new_node(num);
	if (head || new)
		new->next = *head;
	*head = new;
	increment_indexes(new->next);
}
void	push_back(t_node *head, int num)
{
	t_node	*prev;
	t_node	*curr;

	prev = find_back(head);
	curr = new_node(num);
	if (prev == NULL || curr == NULL)
		return ;
	curr->next = prev->next;
	prev->next = curr;
	curr->index = prev->index;
	increment_indexes(prev->next);
}
void	rotate_front(t_node **head)
{
	t_node	*last;

	last = find_back(*head);
	if (*head == NULL || last == *head)
		return ;
		// wip
}
