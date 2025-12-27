/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 11:14:45 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/27 23:27:53 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max(t_list *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

static int	get_min(t_list *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	sort_three(t_list **stack)
{
	int	max;

	max = get_max(*stack);
	if ((*stack)->value == max)
		ra(stack);
	else if ((*stack)->next->value == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = get_min(*stack_a);
	if ((*stack_a)->value == min)
		pb(stack_a, stack_b);
	else if ((*stack_a)->next->value == min)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->value == min)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->next->value == min)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	pa(stack_b, stack_a);
}
