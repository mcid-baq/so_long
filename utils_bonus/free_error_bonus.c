/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:57:08 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/04/12 19:35:21 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_error(t_list *list)
{
	if (list && list->mlx)
		mlx_terminate(list->mlx);
	if (list && list->sm)
		free_map(list);
	if (list && list->img)
		free(list->img);
	if (list)
		free(list);
	exit(1);
}
