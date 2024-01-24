#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
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
			break ;
		i++;
	}
	return (num * neg);
}

t_node	*populate_node(int argc, char **argv)
{
	t_node		*head;
	long int	nb;
	int			i;

	head = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (i == 1)
			head = new_node((int)nb);
		else
			push_back(head, (int)nb);
		i++;
	}
	return (head);
}
