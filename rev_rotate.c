/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 11:15:09 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/29 15:33:09 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	t_list	*before_tail;

	if (!stack || !*stack || (*stack)->next == NULL)
		return ;
	head = *stack;
	tail = *stack;
	while (tail->next)
	{
		before_tail = tail;
		tail = tail->next;
	}
	before_tail->next = NULL;
	tail->next = head;
	*stack = tail;
	tail->prev = NULL;
	head->prev = tail;
}

void	rra(t_list **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
