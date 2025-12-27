/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:04:59 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/27 11:46:49 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *a, t_list *b)
{
	printf("Stack A: ");
	if (!a)
		printf("empty");
	while(a)
	{
		printf("[%d]", a->value);
		a = a->next;
	}
	printf("\nStack B: ");
	if (!b)
		printf("empty");
	while(b)
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

	stack_a = NULL;
	stack_b = NULL;
	parse_args(argc, argv, &stack_a);
	parse_args(argc, argv, &stack_b);
	// //TODO For swap
	// sa(&stack_a);
	// print_list(stack_a, stack_b);
	// printf("\n");
	// sb(&stack_b);
	// print_list(stack_a, stack_b);
	// printf("\n");
	// ss(&stack_a, &stack_b);
	// print_list(stack_a, stack_b);
	// //TODO For push
	// pa(&stack_b, &stack_a);
	// print_list(stack_a, stack_b);
	// printf("\n");
	// pb(&stack_a, &stack_b);
	// print_list(stack_a, stack_b);
	// printf("\n");
	// //TODO For rrotate
	print_list(stack_a, stack_b);
	printf("\n");
	sort_three(&stack_a);
	print_list(stack_a, stack_b);
	printf("\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
}
