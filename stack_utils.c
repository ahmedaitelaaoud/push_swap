/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:44:25 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/29 15:33:26 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_lst(t_list **stack, t_list *new_node)
{
	t_list	*last;

	last = *stack;
	if (!new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->next = NULL;
	new_node->prev = last;
}

void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*tmp;

	current = *stack;
	if (!stack || !(*stack))
		return ;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL;
}

void	free_and_error(t_list **stack, char **args)
{
	ft_free_split(args);
	free_stack(stack);
	ft_error();
}

void	set_index(t_list *stack)
{
	t_list	*ptr;
	t_list	*current;
	int		count;

	ptr = stack;
	while (ptr)
	{
		count = 0;
		current = stack;
		while (current)
		{
			if (ptr->value > current->value)
				count++;
			current = current->next;
		}
		ptr->index = count;
		ptr = ptr->next;
	}
}
