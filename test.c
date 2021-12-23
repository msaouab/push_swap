#include <stdio.h>
#include <stdlib.h>
int	ft_check_dup(int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (*arr);
}

int	main(int ac, char **av)
{
	int	arr[ac];
	int tab[ac];
	int	i = 1;
	while (i < ac)
	{
		arr[i] = atoi(av[i]);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		tab[i] = ft_check_dup(arr);
		printf("%d", tab[i]);
		i++;
	}
}