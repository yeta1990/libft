/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci </var/spool/mail/albgarci>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 03:39:49 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/17 10:56:14 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	c = (unsigned char) c;
	str = (unsigned char *) s;
	while (i < n)
	{
		if (c == str[i])
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
