#include "ft_utils.h"

// this part is skipable, you can use the function that's already in libs.
static int	*allocate_zero_arr(size_t n)
{
	int		*res;

	if (!n)
		return (NULL);
	res = (int *)ft_calloc(n + 1, sizeof(int));
	if (!res)
		return (NULL);
	return (res);
}

static int	ft_max(int *arr, size_t n)
{
	size_t		i;
	int			max;

	i = 0;
	max = 0;
	if (!arr)
		return (0);
	while (i < n)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

static void	ft_replace_order(int *arr, size_t num, int j)
{
	static int	p;
	int			i;

	i = 0;
	if (!j)
		return ;
	while (i < j)
	{
		*(arr + p) = num;
		i++;
		p++;
	}
}

void	ft_countingsort(int arr[], size_t n)
{
	size_t		i;
	size_t		len;
	int			*count;

	len = ft_max(arr, n);
	i = 0;
	if (len > 67108851)
	{
		write(STDERR_FILENO, "Range might overlap memories.\n", 30);
		return ;
	}
	count = allocate_zero_arr(len);
	while (i < n)
		count[arr[i++]] += 1;
	i = 0;
	while (i <= len)
	{
		ft_replace_order(arr, i, count[i]);
		i++;
	}
	free(count);
}

// for testing the function
#include <stdio.h>

int	main(void)
{
	int a[10] = {0,1,9,2,0,4,56,4,3,67108852};

	ft_countingsort(a, sizeof(a) / sizeof(a[0]));
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	return (0);
}

