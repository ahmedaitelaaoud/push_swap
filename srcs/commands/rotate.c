/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 11:15:14 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/27 12:32:35 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list *first;
	t_list *tail;

	if (!stack || !*stack || (*stack)->next == NULL)
		return ;
	first = *stack;
	tail = *stack;
	while(tail->next != NULL)
		tail = tail->next;
	(*stack) = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	tail->next = first;
	first->prev = tail;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
