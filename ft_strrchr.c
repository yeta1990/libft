/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:27:33 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/15 16:49:04 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s2;

	i = ft_strlen(s);
	c = (char) c;
	s2 = (char *)s;
	if (s2[i] == c)
		return (s2 + i);
	while (i--)
	{
		if (s2[i] == c)
			return (s2 + i);
	}
	return (0);
}
