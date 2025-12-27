/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 11:15:14 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/26 19:37:30 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list *node_to_move;
	t_list *head;
	head = (*stack)->next;
	if (!stack || !*stack || (*stack)->next == NULL)
		return ;
	node_to_move = *stack;
	head->prev = NULL;
	while((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
	}
	node_to_move->next = NULL;
	node_to_move->prev = *stack;
	(*stack)->next = node_to_move;
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
