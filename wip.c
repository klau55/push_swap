#include <stdio.h>
#define MAX 2
typedef struct s_struct
{
	int	*arr;
	int	size;
}	t_struct;

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

int	main(void)
{
	int	arr [MAX] = {8,0};
	int	buf;
	int	i;

	if (arr[1] < arr[0])
	{
		pa(arr);
	}
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
