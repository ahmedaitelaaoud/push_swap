/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:02:48 by aait-ela          #+#    #+#             */
/*   Updated: 2026/01/01 20:10:14 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void				print_list(t_list *a, t_list *b);
// check_args.c
void				ft_error(void);
int					check_duplicate(t_list *stack, int value);
int					is_number(const char *str);
long				ft_atol(const char *str);

// pars_init.c
char				**ft_split(char const *str, char delimeter);
void				parse_args(int argc, char **argv, t_list **stack);
void				ft_free_split(char **str);

// stack_utils.c
t_list				*lst_new(int value);
void				add_lst(t_list **stack, t_list *new_node);
void				free_stack(t_list **stack);
void				free_and_error(t_list **stack, char **args);
void				set_index(t_list *stack);

// swap.c
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);

// push.c
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);

// rotate.c
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);

// rev_rotate.c
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
// sort_tiny.c
void				sort_three(t_list **stack);
void				sort_four(t_list **stack_a, t_list **stack_b);
void				sort_five(t_list **stack_a, t_list **stack_b);
// stack_init.c
void				bring_to_top(t_list **stack, int value);
int					lst_size(t_list *stack);
int					is_sorted(t_list *stack);
// sort_big.c
void				sort_big(t_list **stack_a, t_list **stack_b);

#endif
