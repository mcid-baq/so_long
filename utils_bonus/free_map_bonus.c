/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:50:03 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/04/12 19:35:27 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_map(t_list *list)
{
	int	in;

	in = 0;
	while (list->sm[in])
		free(list->sm[in++]);
	free(list->sm);
}
