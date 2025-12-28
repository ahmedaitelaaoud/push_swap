/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:04:59 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/28 12:26:47 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *a, t_list *b)
{
	printf("Stack A: ");
	if (!a)
		printf("empty");
	while (a)
	{
		printf("[%d]", a->value);
		a = a->next;
	}
	printf("\nStack B: ");
	if (!b)
		printf("empty");
	while (b)
	{
		printf("[%d]", b->value);
		b = b->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	parse_args(argc, argv, &stack_a);
	print_list(stack_a, stack_b);
	printf("\n");
	size = lst_size(stack_a);
	if (size == 2)
		sa(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else if (size == 4)
		sort_four(&stack_a, &stack_b);
	else if (size == 5)
		sort_five(&stack_a, &stack_b);
	// else if (size > 5) sort_big(&stack_a, &stack_b);
	print_list(stack_a, stack_b);
	printf("\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
}
