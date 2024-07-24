#include <stdlib.h>

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < (n - 1) - i)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

// for testing the function
// #include <stdio.h>
//
// int	main(void)
// {
// 	int a[5] = {2,3,5,1,0};

// 	bubble_sort(a, 5);
// 	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
// 	{
// 		printf("%d ", a[i]);
// 	}
// 	return (0);
// }

