/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:46:51 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/19 02:12:18 by albgarci         ###   ########.fr       */
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
		return (s2 = ft_strdup(""));
	if (len >= ft_strlen(s))
		size = ft_strlen(s) - start + 1;
	else
		size = len + 1;
	s2 = malloc(sizeof(char) * size);
	if (!s2)
		return (0);
	s2 = ft_memcpy(s2, (s + start), size);
	s2[size - 1] = '\0';
	return (s2);
}
