/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:33:51 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/11/15 11:57:17 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_freeup(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
}

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (word);
}

static void	ft_strcpy(char *word, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] != c)
	{
		word[i] = str[j];
		i++;
		j++;
	}
	word[i] = '\0';
}

static char	*ft_stralloc(char *str, char c, int *k)
{
	char	*word;
	int		start;
	int		len;

	while (str[*k] == c && str[*k] != '\0')
		(*k)++;
	start = *k;
	len = 0;
	while (str[*k] != c && str[*k] != '\0')
	{
		len++;
		(*k)++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	ft_strcpy(word, str, c, start);
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		words;
	int		pos;

	if (str == NULL)
		return (NULL);
	words = ft_wordcount((char *)str, c);
	strs = (char **)malloc(sizeof(char *) * (words + 1));
	if (strs == NULL)
		return (NULL);
	pos = 0;
	i = 0;
	while (i < words)
	{
		strs[i] = ft_stralloc((char *)str, c, &pos);
		if (strs[i] == NULL)
		{
			ft_freeup(strs, i - 1);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
