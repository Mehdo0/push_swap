/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:54:24 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/11/15 13:30:58 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*fill_stack_values_str(char **av,
										t_list *stack_a, long int nb)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(av[1], ' ');
	while (args[i])
	{
		nb = ft_atoi(args[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 0)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	free(args);
	return (stack_a);
}

t_list	*fill_stack_values(int ac, char **av)
{
	t_list		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	if (ac == 2)
		return (fill_stack_values_str(av, stack_a, nb));
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

void	assign_index(t_list *stack_a, int stack_size)
{
	t_list	*ptr;
	t_list	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->content == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->content > value && ptr->index == 0)
			{
				value = ptr->content;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
