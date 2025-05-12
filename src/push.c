/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:59:15 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/11/15 13:40:38 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*envoi le premier element d'une liste dans l'autre*/

static void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	do_pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	do_pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
