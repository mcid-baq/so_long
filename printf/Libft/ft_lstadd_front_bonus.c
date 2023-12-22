/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:35:13 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/22 13:53:31 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front_bonus(t_lb **lst, t_lb *new)
{
	t_lb	*temp;

	if (lst == NULL || new == NULL)
		return ;
	temp = *lst;
	*lst = new;
	new->next = temp;
}
