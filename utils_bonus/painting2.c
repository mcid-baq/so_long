/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:07:26 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/04/16 18:16:40 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	painting2(t_list *list, int y, int x)
{
	if (mlx_image_to_window(list->mlx, list->img->floor, x * 64, y * 64) < 0)
		print_error("Fail to paint ground", list);
	if (list->sm[y][x] == '1' && mlx_image_to_window(list->mlx, \
	list->img->wall, x * 64, y * 64) < 0)
		print_error("Fail to paint wall", list);
	else if (list->sm[y][x] == 'C' && mlx_image_to_window(list->mlx, \
	list->img->collectible, x * 64, y * 64) < 0)
		print_error("Fail to paint window", list);
	else if (list->sm[y][x] == 'E' && (mlx_image_to_window(list->mlx, \
	list->img->exitdown, x * 64, y * 64) < 0 \
	|| mlx_image_to_window(list->mlx, list->img->exitup, x * 64, y * 64) < 0))
		print_error("Fail to paint the exit", list);
	else if (list->sm[y][x] == 'X' && (mlx_image_to_window(list->mlx, \
	list->img->enemyleft, x * 64, y * 64) < 0 \
	|| mlx_image_to_window(list->mlx, list->img->enemyright, x * 64, \
	y * 64) < 0))
		print_error("Fail to paint the enemy", list);
}
