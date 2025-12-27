/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:42:15 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/26 19:32:17 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h> //! For printf (remove before submission if needed)
# include <stdlib.h>
# include <unistd.h>

// --- STRUCTS ---
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

// --- PROTOTYPES ---
void	print_list(t_list *a, t_list *b);
// srcs/parsing/check_args.c
void				ft_error(void);
int					check_duplicate(t_list *stack, int value);
int					is_number(const char *str);
long				ft_atol(const char *str);

// srcs/parsing/pars_init.c
char				**ft_split(char const *str, char delimeter);
void				parse_args(int argc, char **argv, t_list **stack);
void				ft_free_split(char **str);

// srcs/stack/stack_utils.c
t_list				*lst_new(int value);
void				add_lst(t_list **stack, t_list *new_node);
void				free_stack(t_list **stack);
void				free_and_error(t_list **stack, char **args);

// srcs/commands/swap.c
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);

// srcs/commands/push.c
void				pa(t_list **stack_b, t_list **stack_a);
void				pb(t_list **stack_a, t_list **stack_b);

// srcs/commands/rotate.c
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
#endif
