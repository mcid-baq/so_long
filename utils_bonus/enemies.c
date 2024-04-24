/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:36:58 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/04/16 18:11:54 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	move_enemy(t_list *list, int y, int x, int n)
{
	if (list->nmov % 2 == 1)
	{
		list->img->enemyleft->instances[n].enabled = 0;
		list->img->enemyright->instances[n].enabled = 1;
		if (list->sm[y][x + 1] == '0')
		{
			list->sm[y][x + 1] = 'X';
			list->sm[y][x] = '0';
			list->img->enemyleft->instances[n].x += 64;
			list->img->enemyright->instances[n].x += 64;
		}
	}
	else
	{
		list->img->enemyleft->instances[n].enabled = 1;
		list->img->enemyright->instances[n].enabled = 0;
		if (list->sm[y][x - 1] == '0')
		{
			list->sm[y][x - 1] = 'X';
			list->sm[y][x] = '0';
			list->img->enemyleft->instances[n].x -= 64;
			list->img->enemyright->instances[n].x -= 64;
		}
	}
}

void	painting_enemy(t_list *list)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	while (i < list->nx)
	{
		y = list->img->enemyleft->instances[i].y / 64;
		x = list->img->enemyleft->instances[i].x / 64;
		move_enemy(list, y, x, i);
		if (list->sm[list->pyc][list->pxc] == 'X')
		{
			mlx_terminate(list->mlx);
			free(list->img);
			free_map(list);
			free(list);
			ft_printf("YOU HAVE BEEN EATEN\n");
			exit(0);
		}
		i++;
	}
}
