/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:36:46 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/11/15 12:14:01 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

/*structure d'une liste doublement chainer (next & prev)
 avec un index pour faciliter le code apres*/

typedef struct s_list
{
	int				content;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

/* Initialization */

t_list		*fill_stack_values(int ac, char **av);
void		assign_index(t_list *stack_a, int ac);
char		**ft_split(char const *str, char c);

/* Sorting Algorithms */

int			is_sorted(t_list *stack);
void		tiny_sort(t_list **stack);
void		sort(t_list **stack_a, t_list **stack_b);

/* Position */

int			get_lowest_index_position(t_list **stack);
void		get_target_position(t_list **stack_a, t_list **stack_b);

/* Cost */

void		get_cost(t_list **stack_a, t_list **stack_b);
void		do_cheapest_move(t_list **stack_a, t_list **stack_b);

/* Calculate Move */

void		do_move(t_list **a, t_list **b, int cost_a, int cost_b);

/* Operations */

void		do_pa(t_list **stack_a, t_list **stack_b);
void		do_pb(t_list **stack_a, t_list **stack_b);
void		do_sa(t_list **stack_a);
void		do_sb(t_list **stack_b);
void		do_ss(t_list **stack_a, t_list **stack_b);
void		do_ra(t_list **stack_a);
void		do_rb(t_list **stack_b);
void		do_rr(t_list **stack_a, t_list **stack_b);
void		do_rrr(t_list **stack_a, t_list **stack_b);
void		do_rra(t_list **stack_a);
void		do_rrb(t_list **stack_b);

/* Stack Functions */

t_list		*get_stack_bottom(t_list *stack);
t_list		*get_stack_before_bottom(t_list *stack);
t_list		*stack_new(int value);
void		stack_add_bottom(t_list **stack, t_list *new);
int			get_stack_size(t_list	*stack);

/* Utils */

void		free_stack(t_list **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);
int			arg_is_number(char *av);
int			have_duplicates(char **av);
int			arg_is_zero(char *av);

/* Error */

void		exit_error(t_list **stack_a, t_list **stack_b);

/* Input Check */

int			is_correct_input(char **av, int ac);
int			is_correct_input_str(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);

#endif