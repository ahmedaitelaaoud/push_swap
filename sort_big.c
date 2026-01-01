/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:33:57 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/29 15:34:03 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_list *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

static int	get_pos_of_index(t_list *stack, int index_to_find)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index_to_find)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

static void	push_to_b(t_list **stack_a, t_list **stack_b, int range)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
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
		else
			ra(stack_a);
	}
}

static void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max_idx;
	int	max_pos;
	int	size_b;

	while (*stack_b)
	{
		max_idx = get_max_index(*stack_b);
		max_pos = get_pos_of_index(*stack_b, max_idx);
		size_b = lst_size(*stack_b);
		if (max_pos <= size_b / 2)
		{
			while ((*stack_b)->index != max_idx)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->index != max_idx)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	range;
	int	num;

	num = lst_size(*stack_a);
	if (num >= 500)
		range = 33;
	else
		range = 15;
	push_to_b(stack_a, stack_b, range);
	push_to_a(stack_a, stack_b);
}
