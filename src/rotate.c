/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:33:48 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/11/15 13:40:44 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*le premier element devient le dernier et 
tout les autres coulisses vers le haut*/

static void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	do_rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	do_rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
