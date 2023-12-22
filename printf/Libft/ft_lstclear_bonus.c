/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:17:36 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/22 13:53:03 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_bonus(t_lb **lst, void (*del)(void *))
{
	t_lb	*temp;
	t_lb	*auxi;
	size_t	auxilst;

	auxilst = ((auxi = *lst) == 0);
	if (auxilst)
		return ;
	while (auxi)
	{
		temp = auxi->next;
		del(auxi->content);
		free(auxi);
		auxi = temp;
	}
	*lst = NULL;
}
