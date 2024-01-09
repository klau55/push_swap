#include <stdio.h>
#define MAX 3

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
}	t_node;

int	done_checker(int *a)
{
	int	i;

	i = 0;
	while (a[i + 1] && (i + 1 < MAX))
	{
		if (a[i + 1] < a[i])
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

void pa(int *arr)
{
	int	buf;

	buf = arr[1];
	arr[1] = arr[0];
	arr[0] = buf;
}

void	ra(int *arr)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	temp = arr[0];
	while (i < MAX - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[MAX - 1] = temp;
	printf("ra\n");
}

void	rra(int *arr)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	temp = arr[MAX - 1];
	i = MAX - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = temp;
	printf("rra\n");
}

void	sa(int *arr)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	printf("sa\n");
}

int	main(int argc, char **argv)
{
	int	arr [MAX] = {4, 1, 8};
	int	buf;
	int	i;
	t_node	stack_a;

	i = 0;
/*	while (argv[i + 1] && argc != 4)
	{
		stack_a[i].num = ft_atoi(argv[i + 1]);
		stack_a[i].index = i;
		i++;
	} */
	if (arr[0] < arr[1] && arr[0] > arr[2])
		ra(arr);
	if (arr[0] > arr[1])
		sa(arr);
	if (arr[1] > arr[2])
		rra(arr);
	if (arr[0] > arr[1])
		sa(arr);
	if (done_checker(arr) == 1)
		return (-1);
	i = 0;
	while (i < MAX)
	{
		printf("%d", arr[i]);
		i++;
	}
	return (0);
}
