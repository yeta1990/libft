/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:19:30 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/21 10:45:01 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	destlen = 0;
	srclen = 0;
	while (dest[destlen] && destlen < size)
		destlen++;
	while (src[srclen])
		srclen++;
	if (destlen == size)
		return (size + srclen);
	if (size > destlen)
	{
		while (src && src[i] && i < size - destlen - 1)
		{
			dest[destlen + i] = src[i];
			i++;
		}
		dest[destlen + i] = '\0';
	}
	return (destlen + srclen);
}
