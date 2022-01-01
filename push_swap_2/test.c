#include <stdio.h>
#include <stdlib.h>
# define false 0
# define true 1

int	*true_false(int *tab, int size, int per_grp)
{
	int	i;
	int	j;

	i = per_grp;
	j = i + 1;
	while (i < size)
	{
		while (j < i)
		{
			if (tab[j] < tab[i])
			{
				tab[j] = tab[i];
				tab[i] = true;
			}
			else
				tab[i] = false;
			j++;
		}
		i++;
	}
	i = 0;
	j = i + 1;
	while (i < per_grp)
	{
		while (j < i)
		{
			if (tab[j] < tab[i])
			{
				tab[j] = tab[i];
				tab[i] = true;
			}
			else
				tab[i] = false;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		printf("%d\t - %d\n", i, tab[i]);
		i++;
	}
	return (tab);
}

int	main()
{
	int	tab[10] = {4, -7, -2, -4, 3, -9, -1, 6, 2, 10};
	int	i;
	int size = 10;
	int per = 2;
	true_false(tab, size, per);
}