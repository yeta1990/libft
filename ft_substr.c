/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:46:51 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/17 12:54:07 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*s2;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		s2 = malloc(1);
		s2[0] = '\0';
		return (s2);
	}
	if (len > ft_strlen(s))
		size = ft_strlen(s) - start;
	else
		size = len + 1;
	s2 = malloc(sizeof(char) * size);
	if (!s2)
		return (0);
	s2 = ft_memcpy(s2, (s + start), size);
	s2[len] = '\0';
	return (s2);
}
