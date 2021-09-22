/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci </var/spool/mail/albgarci>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:13:15 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/22 11:55:50 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*item;

	if (!lst)
		return (0);
	item = 0;
	new_list = item;
	while (lst)
	{
		item = ft_lstnew(f(lst->content));
		if (!item)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		lst = lst->next;
		ft_lstadd_back(&new_list, item);
	}
	return (new_list);
}
