/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:18:26 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/17 12:01:29 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static int ft_first_oc(char *s1, char *set);
//static int ft_last_oc(char *s1, char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	if (!s1 || !set)
		return ((char *)s1);
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strrchr(set, s1[j]))
		j--;
	s = ft_substr(s1, i, j - i + 1);
	if (!s)
		return (0);
	return (s);
}
