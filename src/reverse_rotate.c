/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:42:08 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/11/13 11:39:40 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*decale le dernier element en premiere position
et fait glisser tout les elements vers le bas*/

static void	rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*before_tail;

	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	do_rra(t_list **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

void	do_rrb(t_list **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	do_rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
