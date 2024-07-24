#include <stdlib.h>

// this part is skipable, you can use the function that's already in libs.
static int	*ft_int_calloc(size_t n)
{
	size_t	i;
	int		*res;

	i = 0;
	if (!n)
		return (NULL);
	res = (int *)malloc((n + 1) * sizeof(int));
	if (!res)
		return (NULL);
	while (i < n)
	{
		res[i++] = 0;
	}
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

static void	*ft_replace_order(int *arr, size_t num, int j)
{
	int	i;

	i = 0;
	if (!j)
		return (arr);
	while (i < j)
	{
		*arr = num;
		arr++;
		i++;
	}
	return (arr);
}

void	ft_countingsort(int arr[], size_t n)
{
	size_t		i;
	size_t		len;
	int			*pos;
	int			*count;

	len = ft_max(arr, n);
	i = 0;
	pos = arr;
	count = ft_int_calloc(len);
	while (i < n)
	{
		count[arr[i++]] += 1;
	}
	i = 0;
	while (i <= len)
	{
		pos = ft_replace_order(pos, i, count[i]);
		i++;
	}
	free(count);
}

// for testing the function
#include <stdio.h>

int	main(void)
{
	int a[10] = {0,1,9,2,0,5,4,56,4,3};

	ft_countingsort(a, sizeof(a) / sizeof(a[0]));
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	return (0);
}

