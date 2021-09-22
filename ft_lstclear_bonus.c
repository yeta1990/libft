/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci </var/spool/mail/albgarci>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 13:59:03 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/22 11:54:55 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*aux_next;

	aux = *lst;
	while (aux)
	{
		aux_next = aux->next;
		del(aux->content);
		free(aux);
		aux = aux_next;
	}
	*lst = NULL;
}
