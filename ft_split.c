/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:03:40 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/18 17:15:05 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <string.h>

void	assign_mem(char **p, char *str, char c);
char	**copy_words(char **p, char *str, char c);
//char	**copy_str(char *str);

char **ft_split(char const *str, char c)
{
	int		i;
	int		words;
	int		in_word;
	char	**p;

	i = 0;
	words = 0;
	in_word = 1;
/*	if (c == '\0')
	{
	//	p = 0;
		p = malloc(sizeof(char *) * 2);
		if (!p)
			return (0);
		p[0] = ft_strdup(str);
		p[1] = 0;
	}
*/	
/*	while (str[i] == c)
		i++;
	if ((size_t) i == ft_strlen(str))
		return (0);
	else
		i = 0;
*/	while (str[i++])
	{
		if (c != str[i] && str[i + 1] == 0)
			words++;
		else if (c != str[i])
			in_word = 1;
		else if (c == str[i] && (in_word))
		{
			in_word = 0;
			words++;
		}
	}
	if (!(p = malloc(sizeof(char *) * (words + 1))))
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
			p[words++] = malloc(sizeof(char) * (size + 1));
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
		if (c != str[i] && str[i + 1] == 0 && j == 0)
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
