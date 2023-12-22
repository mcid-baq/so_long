/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:38:59 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/22 13:54:48 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lb	*ft_lstnew_bonus(void *content)
{
	t_lb	*new;

	new = (t_lb *)malloc(sizeof(t_lb));
	if (new == 0)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}
