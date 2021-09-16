/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:49:06 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/16 18:58:57 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c);

int	ft_atoi(const char *str)
{
	long int	i;
	long int	num;
	long int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_is_space (str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * sign);
}

static int	ft_is_space(char c)
{
	if (c == ' ' || c == 9 || c == 10 || c == 11 || c == 12 || c == 13)
		return (1);
	return (0);
}
