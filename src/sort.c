/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:57:08 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/11/15 11:20:02 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_all_save_three(t_list **stack_a, t_list **stack_b)
{
	int	list_size;
	int	pushed;
	int	i;

	list_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (list_size > 6 && i < list_size && pushed < list_size / 2)
	{
		if ((*stack_a)->index <= list_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (list_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

static void	shift_stack(t_list **stack_a)
{
	int	lowest_pos;
	int	list_size;

	list_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > list_size / 2)
	{
		while (lowest_pos < list_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
