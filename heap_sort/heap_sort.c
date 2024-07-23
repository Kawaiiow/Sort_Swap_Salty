/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:38:13 by kawaii            #+#    #+#             */
/*   Updated: 2024/07/23 22:46:25 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	heapify(int *arr, int n, int i)
{
	int	largest;
	int	left;
	int	right;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void	ft_heapsort(int *arr, int n)
{
	int	i;

	i = n / 2 - 1;
	while (i >= 0)
		heapify(arr, n, i--);
	i = n - 1;
	while (i >= 0)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i--, 0);
	}
}
