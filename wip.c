#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
}	t_node;

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

void pa(t_node *stack_a)
{
	int	buf;

	buf = stack_a[1].num;
	stack_a[1].num = stack_a[0].num;
	stack_a[0].num = buf;
}

void	ra(t_node *stack_a)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	temp = stack_a[0].num;
	while (i < MAX - 1)
	{
		stack_a[i].num = stack_a[i + 1].num;
		i++;
	}
	stack_a[MAX - 1].num = temp;
	printf("ra\n");
}

void	rra(t_node *stack_a)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	temp = stack_a[MAX - 1].num;
	i = MAX - 1;
	while (i > 0)
	{
		stack_a[i].num = stack_a[i - 1].num;
		i--;
	}
	stack_a[0].num = temp;
	printf("rra\n");
}

void	sa(t_node *stack_a)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	temp = stack_a[0].num;
	stack_a[0].num = stack_a[1].num;
	stack_a[1].num = temp;
	printf("sa\n");
}

int main(int argc, char **argv)
{
	int		*arr;
	t_node	*stack_a;
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
		stack_a[i].num = ft_atoi(argv[i + 1]);
		stack_a[i].index = i;
		i++;
	}
	if (argc == 3)
	{
		if (!stack_a[0].num)
			return (-1);
		if (stack_a[0].num > stack_a[1].num)
			pa(stack_a);
	}
	if (argc == 4)
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
