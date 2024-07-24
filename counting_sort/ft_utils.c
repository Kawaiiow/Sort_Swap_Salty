#include "ft_utils.h"

static void	ft_bzero(void *set, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = set;
	while (i < n)
		str[i++] = 0;
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*set;

	if ((n * size) == 0)
	{
		set = (void *)malloc(1);
		if (set == NULL)
			return (NULL);
		ft_bzero(set, 1);
		return (set);
	}
	set = (void *)malloc(n * size);
	if (set == NULL)
		return (NULL);
	ft_bzero(set, (n * size));
	return (set);
}