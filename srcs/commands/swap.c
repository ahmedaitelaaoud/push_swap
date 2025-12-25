/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 11:15:17 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/25 16:02:14 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	*stack = second;
	first->next = first->next->next;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	if (first->next != NULL)
		first->next->prev = first;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
