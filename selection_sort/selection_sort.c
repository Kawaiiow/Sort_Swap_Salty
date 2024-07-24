#include <stdlib.h>

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_selection_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	temp;
	int	min_cord;

	i = 0;
	while (i < n - 1)
	{
		min_cord = i;
		j = i;
		temp = arr[i];
		while (j < n)
		{
			if (arr[j] < temp)
			{
				temp = arr[j];
				min_cord = j;
			}
			j++;
		}
		if (min_cord != i)
			swap(&arr[i], &arr[min_cord]);
		i++;
	}
}

// for testing the function
// #include <stdio.h>
//
// int	main(void)
// {
// 	int a[15] = {1,2,4,1,23,4,1,4,231,234,54,3,345,56,34};

// 	ft_selection_sort(a, sizeof(a) / sizeof(a[0]));
// 	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
// 	{
// 		printf("%d ", a[i]);
// 	}
// 	return (0);
// }
