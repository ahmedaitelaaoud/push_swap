/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:11:09 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/17 17:06:43 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

//*Error management (Alarm)
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
//*Add the new node to stack
void	add_lst(t_list **stack, t_list *new_node)
{
	t_list	*last;

	last = *stack;
	//*Check if stack is empty (not crush)
	if (*stack == NULL)
		// TODO: Should know what problem cause if i don't check the NULL
	{
		*stack = new_node;
		new_node->prev = NULL;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}
//*Add a new node
t_list	*lst_new(int value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

//*Scans Stack A to ensure this new number isn't already inside.
int	check_duplicate(t_list *stack, int value)
{
	t_list	*current_node;

	current_node = stack;
	while (current_node != NULL)
	{
		if (current_node->value == value)
			return (1);
		current_node = current_node->next;
	}
	return (0);
}
//*Checks if the string looks like a number.
int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
//*Converts the accepted string into a raw number (Long).
long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	parse_args(int argc, char **argv, t_list **stack)
{
	int		i;
	long	nb;

	i = 1;
	nb = 0;
	while (i < argc)
	{
		if (is_number(argv[i]) == 0)
			ft_error();
		nb = ft_atol(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			ft_error();
		if (check_duplicate(*stack, (int)nb) == 1)
			ft_error();
		add_lst(stack, lst_new((int)nb));
		i++;
	}
}
void	print_lst(t_list *stack)
{
	while (stack)
	{
		printf("Value: %d\n", stack->value);
		stack = stack->next;
	}
}
int	main(int argc, char **argv)
{
	t_list	*stack;

	stack = NULL;
	parse_args(argc, argv, &stack);
	print_lst(stack);
}
