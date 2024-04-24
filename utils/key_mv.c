/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:31:34 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/04/16 16:24:51 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_collectible(t_list *list, int y, int x)
{
	int	in;

	in = 0;
	list->ccurrent++;
	list->sm[y][x] = '0';
	while (in < list->nc)
	{
		if (list->img->collectible->instances[in].x == x * 64
			&& list->img->collectible->instances[in].y == y * 64)
		{
			list->img->collectible->instances[in].enabled = false;
			break ;
		}
		in++;
	}
}

void	movement(t_list *list, int y, int x)
{
	if (list->sm[y][x] == '1')
		return ;
	list->pyc = y;
	list->pxc = x;
	list->img->character->instances[0].x = x * 64;
	list->img->character->instances[0].y = y * 64;
	ft_printf("Steps: %d\n", ++list->nmov);
	if (list->sm[y][x] == 'C')
		check_collectible(list, y, x);
	else if (list->sm[y][x] == 'E' && list->ccurrent == list->nc)
	{
		mlx_terminate(list->mlx);
		free(list->img);
		free_map(list);
		free(list);
		ft_printf("YOU WON\n");
		exit(0);
	}
}

void	key_mv(mlx_key_data_t keydata, void *param)
{
	t_list	*list;

	list = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(list->mlx);
		free(list->img);
		free_map(list);
		free(list);
		exit(0);
	}
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_RELEASE)
		movement(list, list->pyc - 1, list->pxc);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_RELEASE)
		movement(list, list->pyc, list->pxc - 1);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_RELEASE)
		movement(list, list->pyc + 1, list->pxc);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_RELEASE)
		movement(list, list->pyc, list->pxc + 1);
}
