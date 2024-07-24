#include <stdlib.h>

void	ft_insertion_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	select;

	i = 1;
	while (i < n)
	{
		j = i - 1;
		select = arr[i];
		while (j >= 0 && arr[j] > select)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = select;
		i++;
	}
}

// for testing the function
// #include <stdio.h>

// int	main(void)
// {
// 	int a[10] = {0,0,5,3,0,9,2,3,7,2};

// 	ft_insertion_sort(a, sizeof(a) / sizeof(a[0]));
// 	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
// 		printf("%d ", a[i]);
// 	return (0);
// }
