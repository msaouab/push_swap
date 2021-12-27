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

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a->filled_size == 0)
		return ;
	if (stack_b->filled_size != 0)
	{
		i = stack_b->filled_size - 1;
		while (i >= 0)
		{
			stack_b->tab[i + 1] = stack_b->tab[i];
			i--;
		}
	}
	stack_b->tab[0] = stack_a->tab[0];
	i = 0;
	while (i <= stack_a->filled_size - 1)
	{
		stack_a->tab[i - 1] = stack_a->tab[i];
		i++;
	}
	stack_a->filled_size -= 1;
	stack_b->filled_size += 1;
}


int	main()
{
	t_stack stack_a;
	t_stack stack_b;
	int arr_a[ARGS_NUM] =  {1, 2, 3, 4, 5};
	int arr_b[ARGS_NUM] =  {6, 7, 8, 9, 10};
	int	i = 0;
	
	initialize_given_stack(&stack_a, ARGS_NUM);
	initialize_given_stack(&stack_b, ARGS_NUM);
	// stack_a.tab = malloc(sizeof(int) * 5);
	// stack_b.tab = malloc(sizeof(int) * 5);

	///take args and convert them to int and store them within the stack a
	//therefor ==> stack_a size == ARGS_NUM
	//stack_b size == 0
	memcpy(stack_a.tab, arr_a, 5 * sizeof(int));
	memcpy(stack_b.tab, arr_b, 5 * sizeof(int));
	stack_a.filled_size = 5;
	stack_b.filled_size = 5;
	
	push_to_b(&stack_a, &stack_b);
i = 0;
	printf("stack a :\n");
	while (i < stack_a.filled_size)
		printf("%d\n", stack_a.tab[i++]);
i = 0;
	printf("stack b :\n");
	while (i < stack_b.filled_size)
		printf("%d\n", stack_b.tab[i++]);
}