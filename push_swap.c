#include "push_swap.h"

int	done_checker(t_node *stack_a)
{
	int	i;

	i = 0;
	while (stack_a[i + 1].num && (i + 1 < MAX))
	{
		if (stack_a[i + 1].num < stack_a[i].num)
			return (1);
		i++;
	}
	return (0);
}

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



int two(t_node *stack_a)
{
	if (!stack_a[0].num)
		return (-1);
	if (stack_a[0].num > stack_a[1].num)
		sa(stack_a);
	return (0);
}

int	three(t_node *stack_a)
{
	if (!stack_a[0].num)
		return (-1);
	if (stack_a[0].num < stack_a[1].num && stack_a[0].num > stack_a[2].num)
		ra(stack_a);
	if (stack_a[0].num > stack_a[1].num)
		sa(stack_a);
	if (stack_a[1].num > stack_a[2].num)
		rra(stack_a);
	if (stack_a[0].num > stack_a[1].num)
		sa(stack_a);
	if (done_checker(stack_a) == 1)
		return (-1);
	else
		return (0);
}

int four_to_n(t_node *stack_a, t_node *stack_b)
{
	stack_a = NULL;
	stack_b = NULL;
	return (-1);
}

int main(int argc, char **argv)
{
	int		*arr;
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;


	if (argc == 2)
		return (printf("%d\n", ft_atoi(argv[1])));
	if (argc < 3 || argc > 4)
		return (printf("no go, only 1 to 3 digits accepted\n"));
	arr = malloc((argc - 1) * sizeof(int));

	if (arr == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (1);
	}
	stack_a = malloc((argc - 1) * sizeof(t_node));
	if (stack_a == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free(arr);
		return (1);
	}
	i = 0;
	while (argv[i + 1] && i < argc - 1)
	{
		if (1 == ft_isdigit((char)argv[i + 1]))
			return (printf("Only digits allowed, why put %s?\n", argv[i + 1]));
		stack_a[i].num = ft_atoi(argv[i + 1]);
		stack_a[i].index = i;
//		printf("*stack number %d num: %d, index: %d\n", i, stack_a[i].num, stack_a[i].index);
		i++;
	}
	if (argc == 3)
	{
		if (-1 == two(stack_a))
			return (-1);
	}
	if (argc == 4)
	{
		if (-1 == three(stack_a))
			return (-1);
	}
	if (argc == 5)
	{
		stack_b = NULL;
		if (-1 == four_to_n(stack_a, stack_b))
			return (-1);
	}
	i = 0;
	while (i < (argc - 1))
	{
//		printf("%d---\n", i);
		printf("%d,", stack_a[i].num);
		i++;
	}
	return (0);
}
