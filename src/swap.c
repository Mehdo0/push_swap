/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:29:32 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/11/13 11:40:34 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*echange les deux premiers elements de la liste*/

static void	swap(t_list *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	do_sa(t_list **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

void	do_sb(t_list **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

void	do_ss(t_list **stack_a, t_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
