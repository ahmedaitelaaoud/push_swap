#include "push_swap.h"

void	set_index(t_list *stack)
{
	t_list *ptr;
	t_list *current;
	int count;

	ptr = stack;
	while(ptr)
	{
		count = 0;
		current = stack;
		while(current)
		{
			if(ptr->value > current->value)
				count++;
			current = current->next;
		}
		ptr->index = count;
		ptr = ptr->next;
	}
}

static int	get_max_index(t_list *stack)
{
	int max = stack->index;
	while(stack)
	{
		if(stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

static int get_pos_of_index(t_list *stack, int index_to_find)
{
	int pos = 0;
	while (stack)
	{
		if (stack->index == index_to_find)
			return(pos);
		pos++;
		stack = stack->next;
	}
	return -1;
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int i = 0;
	int range = 15;
	while(*stack_a)
	{
		if ((*stack_a)->index < i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index > i + range)
			ra(stack_a);
	}
	while (*stack_b)
	{
		int max_idx = get_max_index(*stack_b);
		int max_pos = get_pos_of_index(*stack_b, max_idx);
		int size_b = lst_size(*stack_b);
		if (max_pos <= size_b / 2)
		{
			while((*stack_b)->index != max_idx)
				rb(stack_b);
		}
		else
		{
			while((*stack_b)->index != max_idx)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}
