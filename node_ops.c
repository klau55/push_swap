# include "push_swap.h"

void	swap_values(t_node *a, t_node *b)
{
	int	tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = a->num;
	a->num = b->num;
	b->num = tmp;
}

t_node	*at_ind(t_node *head, int index)
{
	t_node	*node;

	node = head;
	while (node->index != index && node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

void	swap_indexes(t_node *a, t_node *b)
{
	int	tmp;

	if (a == NULL || b == NULL)
		return ;
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
	new->top_part = true;
	new->cheapest = false;
	new->push_price = 0;
	new->next = NULL;
	return (new);
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
		(tail->index)--;
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

t_node	*findby_index(t_node *head, int index)
{
	t_node	*node;

	node = head;
	while (node->index != index && node->next != NULL)
		node = node->next;
	return (node);
}
void	rotate_front(t_node **head)
{
	t_node	*last;

	last = find_back(*head);
	if (*head == NULL || last == *head)
		return ;
	findby_index(*head, len(*head) - 2)->next = NULL;
	last->next = *head;
	*head = last;
	(*head)->index = 0;
	increment_indexes((*head)->next);
}

void	rotate_back(t_node **head)
{
	t_node	*last;
	t_node	*temp;
	int		last_ind;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	last = find_back(*head);
	last_ind = last->index;
	temp->next = NULL;
	last->next = temp;
	decrement_indexes(*head);
	find_back(*head)->index = last_ind;
}

void	pop_front(t_node **head)
{
	t_node	*front;

	if (*head == NULL)
		return ;
	front = *head;
	*head = (*head)->next;
	decrement_indexes(*head);
	free(front);
}

t_node	*back(t_node *node)
{
	while (node && node->next != NULL)
		node = node->next;
	return (node);
}

int	distance(t_node *first, t_node *last)
{
	int	res;

	res = 0;
	while (first && first != last)
	{
		res++;
		first = first->next;
	}
	return (res);
}

int	len(t_node *head)
{
	if (!head)
		return (0);
	return (distance(head, back(head)) + 1);
}

void set_indexes(t_node *head)
{
	t_node	*node;
	int		i;

	i = 0;
	node = head;
	while (node)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}
