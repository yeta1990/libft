/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci </var/spool/mail/albgarci>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:30:42 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/17 09:57:10 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	ft_memmove(s3, (char *)s1, ft_strlen(s1));
	ft_memmove(s3 + ft_strlen(s1), (char *)s2, ft_strlen(s2));
	s3[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (s3);
}
