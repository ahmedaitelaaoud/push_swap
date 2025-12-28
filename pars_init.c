/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:45:10 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/25 22:58:17 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(int argc, char **argv, t_list **stack)
{
	int		i;
	int		j;
	long	nb;
	char	**args;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		j = 0;
		while (args[j])
		{
			if (is_number(args[j]) == 0)
				free_and_error(stack, args);
			nb = ft_atol(args[j]);
			if (nb < -2147483648 || nb > 2147483647)
				free_and_error(stack, args);
			if (check_duplicate(*stack, nb) == 1)
				free_and_error(stack, args);
			add_lst(stack, lst_new(nb));
			j++;
		}
		ft_free_split(args);
		i++;
	}
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
