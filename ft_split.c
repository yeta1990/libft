/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:03:40 by albgarci          #+#    #+#             */
/*   Updated: 2021/11/02 19:03:04 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		assign_mem_mod(char **p, char *str, char c);
char	**copy_words_mod(char **p, char *str, char c, int *i);
int		count_words_mod(char const *str, char c);
int		assign_mem_mod_2(char **p, int *words, int size);

char	**ft_split(char const *str, char c)
{
	int		i;
	int		words;
	char	**p;

	i = 0;
	if (str == 0)
	{
		p = malloc(sizeof(char *));
		if (!p)
			return (0);
		p[0] = 0;
		return (p);
	}
	words = count_words_mod(str, c);
	p = malloc(sizeof(char *) * (words + 1));
	if (!(p) || assign_mem_mod(p, (char *)str, c) == 0)
		return (0);
	return (copy_words_mod(p, (char *)str, c, &i));
}

int	assign_mem_mod(char **p, char *str, char c)
{
	int	i;
	int	size;
	int	words;

	i = -1;
	size = 0;
	words = 0;
	while (str[++i])
	{
		if (c != str[i] && str[i + 1] == 0)
		{
			if (assign_mem_mod_2(p, &words, size + 2) == 0)
				return (0);
		}
		else if (c != str[i])
			size++;
		else if (c == str[i] && size > 0)
		{
			if (assign_mem_mod_2(p, &words, size + 1) == 0)
				return (0);
			size = 0;
		}
	}
	p[words] = 0;
	return (1);
}

char	**copy_words_mod(char **p, char *str, char c, int *i)
{
	int	j;
	int	word;

	*i = -1;
	j = 0;
	word = 0;
	while (str[++(*i)])
	{
		if (c != str[*i] && str[*i + 1] == 0)
		{	
			p[word][j] = str[*i];
			p[word][j + 1] = '\0';
		}	
		else if (c != str[*i])
			p[word][j++] = str[*i];
		else if (c == str[*i] && j > 0)
		{
			p[word][j] = '\0';
			word++;
			j = 0;
		}
	}
	return (p);
}

int	count_words_mod(char const *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (c != str[i] && !i)
			words++;
		else if (c != str[i] && c == str[i - 1])
			words++;
		i++;
	}
	return (words);
}

int	assign_mem_mod_2(char **p, int *words, int size)
{
	int	i;

	i = 0;
	p[*words] = malloc(sizeof(char) * size);
	if (!p[*words])
	{
		i = *words - 1;
		while (i >= 0)
		{
			free(p[i]);
			i--;
		}
		free(p);
		return (0);
	}
	else
		(*words)++;
	return (1);
}
