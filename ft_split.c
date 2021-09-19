/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:03:40 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/19 03:42:22 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	assign_mem(char **p, char *str, char c);
char	**copy_words(char **p, char *str, char c);

char	**ft_split(char const *str, char c)
{
	int		i;
	int		words;
	char	**p;

	i = 0;
	words = 0;
	if (str == 0)
	{
		p = malloc(sizeof(char *));
		p[0] = 0;
		return (p);
	}
	while (str[i])
	{
		if (c != str[i] && !i)
			words++;
		else if (c != str[i] && c == str[i - 1])
			words++;
		i++;
	}
	p = malloc(sizeof(char *) * (words + 1));
	if (!(p))
		return (0);
	assign_mem(p, (char *)str, c);
	return (copy_words(p, (char *)str, c));
}

void	assign_mem(char **p, char *str, char c)
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
			p[words++] = malloc(sizeof(char) * (size + 2));
		else if (c != str[i])
			size++;
		else if (c == str[i] && size > 0)
		{
			p[words++] = malloc(sizeof(char) * (size + 1));
			size = 0;
		}
	}
	p[words] = 0;
}

char	**copy_words(char **p, char *str, char c)
{
	int	i;
	int	j;
	int	word;

	i = -1;
	j = 0;
	word = 0;
	while (str[++i])
	{
		if (c != str[i] && str[i + 1] == 0)
		{	
			p[word][j] = str[i];
			p[word][j + 1] = '\0';
		}	
		else if (c != str[i])
			p[word][j++] = str[i];
		else if (c == str[i] && j > 0)
		{	
			p[word][j] = '\0';
			word++;
			j = 0;
		}
	}
	return (p);
}
