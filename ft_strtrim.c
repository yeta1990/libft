/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:18:26 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/20 13:37:36 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !set)
		return (0);
	j = ft_strlen(s1);
	if (!set)
	{
		s = ft_strdup(s1);
		if (!s)
			return (0);
		return (s);
	}
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strrchr(set, s1[j]))
		j--;
	s = ft_substr((char *)s1, i, j - i + 1);
	if (!s)
		return (0);
	return (s);
}
