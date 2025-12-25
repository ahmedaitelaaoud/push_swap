/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:04:59 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/25 16:02:22 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*tmp;

	stack = NULL;
	parse_args(argc, argv, &stack);
	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	free_stack(&stack);
}
