#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARGS_NUM 5

typedef struct s_stack
{
	int	*tab;
	int	filled_size;
}	t_stack;

void	initialize_given_stack(t_stack *given_stack, int stack_size)
{
	given_stack->filled_size = 0;
	given_stack->tab = malloc(sizeof(int) * stack_size);
}

void	rotate_a(t_stack *stack_a)
{
	int	tmp;
	int	i;

	if (stack_a->filled_size == 0)
		return ;
	tmp = stack_a->tab[0];
	i = 0;
	while (i < stack_a->filled_size - 1)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	stack_a->tab[i] = tmp;
	ft_putstr("ra\n");
}

int	main()
{
	t_stack stack_a;
	int arr_a[ARGS_NUM] =  {1, 2, 3, 4, 5};
	int	i = 0;

	initialize_given_stack(&stack_a, ARGS_NUM);
	memcpy(stack_a.tab, arr_a, 5 * sizeof(int));
	stack_a.filled_size = 5;
	i = 0;
	printf("stack a: befor\n");
	while (i < stack_a.filled_size)
		printf("%d\n", stack_a.tab[i++]);
	rotate_a(&stack_a);
	i = 0;
	printf("stack a: after\n");
	while (i < stack_a.filled_size)
		printf("%d\n", stack_a.tab[i++]);
}