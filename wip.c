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

int	main(void)
{
	int	arr[MAX]= {3, 2};
	int	buf;
	int	i;

	if (arr[1] < arr[0])
	{
		pa(arr);
	}
	if (done_checker(arr) == 1)
		return (-1);
	i = 0;
	while (arr[i] && (i < MAX))
	{
		printf("%d", arr[i]);
		i++;
	}
	return (0);
}
