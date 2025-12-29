/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 11:14:36 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/29 15:32:50 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_position(t_list *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	lst_size(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	bring_to_top(t_list **stack, int value)
{
	int	pos;
	int	size;

	pos = get_position(*stack, value);
	size = lst_size(*stack);
	if (pos <= size / 2)
	{
		while ((*stack)->value != value)
			ra(stack);
	}
	else
		while ((*stack)->value != value)
			rra(stack);
}
