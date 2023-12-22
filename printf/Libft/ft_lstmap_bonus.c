/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:02:01 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/22 13:56:56 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lb	*ft_lstmap_bonus(t_lb *lst,
							void *(*f)(void *), void (*del)(void *))
{
	t_lb	*actual;
	t_lb	*head;

	if (lst == 0)
		return (NULL);
	head = malloc(sizeof(t_lb));
	if (head == 0)
		return (NULL);
	actual = head;
	actual->content = f(lst->content);
	while (lst->next)
	{
		lst = lst->next;
		actual->next = malloc(sizeof(t_lb));
		if (!actual->next)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		actual->next->content = f(lst->content);
		actual = actual->next;
	}
	actual->next = NULL;
	return (head);
}
