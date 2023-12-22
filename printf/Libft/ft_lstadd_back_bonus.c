/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:26:02 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/22 13:52:16 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back_bonus(t_lb **lst, t_lb *new)
{
	t_lb	*temp;

	temp = ft_lstlast(*lst);
	if (temp == 0)
		*lst = new;
	else
		temp->next = new;
}
