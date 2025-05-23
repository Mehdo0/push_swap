/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:53:32 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/11/15 13:21:00 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	nbstr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

int	is_correct_input_str(char **av)
{
	int		i;
	char	**args;
	int		nb_zeros;

	i = 0;
	nb_zeros = 0;
	args = ft_split(av[1], ' ');
	while (args[i])
	{
		if (!arg_is_number(args[i]))
			return (0);
		nb_zeros += arg_is_zero(args[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (have_duplicates(args))
		return (0);
	return (1);
}
