#include <stdio.h>

int	*ft_check_dup(int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = i + 1;
		while (j < 5)
		{
			if (arr[i] == arr[j])
				printf("error\n");
			j++;
		}
		i++;
	}
	return (arr);
}

int	main()
{
	int	i = 0;
	int	tab[5] = {1, 2, 3, 4, 5};
	ft_check_dup(tab);
	while (i < 5)
	{
		printf("%d\n", tab[i++]);
	}

}