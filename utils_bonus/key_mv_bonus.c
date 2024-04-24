/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mv_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:31:34 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/04/16 18:00:00 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	if (list->ccurrent >= list->nc)
	{
		list->img->exitdown->instances[0].enabled = 0;
		list->img->exitup->instances[0].enabled = 1;
	}
}

void	move_generic(t_list *list, int movem)
{
	list->img->characterup->instances[0].enabled = 0;
	list->img->characterdown->instances[0].enabled = 0;
	list->img->characterleft->instances[0].enabled = 0;
	list->img->characterright->instances[0].enabled = 0;
	list->img->characterup->instances[0].x = list->pxc * 64;
	list->img->characterup->instances[0].y = list->pyc * 64;
	list->img->characterdown->instances[0].x = list->pxc * 64;
	list->img->characterdown->instances[0].y = list->pyc * 64;
	list->img->characterleft->instances[0].x = list->pxc * 64;
	list->img->characterleft->instances[0].y = list->pyc * 64;
	list->img->characterright->instances[0].x = list->pxc * 64;
	list->img->characterright->instances[0].y = list->pyc * 64;
	if (movem == 0)
		list->img->characterup->instances[0].enabled = 1;
	else if (movem == 1)
		list->img->characterleft->instances[0].enabled = 1;
	else if (movem == 2)
		list->img->characterdown->instances[0].enabled = 1;
	else if (movem == 3)
		list->img->characterright->instances[0].enabled = 1;
	painting_enemy(list);
}

void	movement(t_list *list, int y, int x, int movem)
{
	char	*nbr;
	char	*full;

	if (list->sm[y][x] == '1')
		return ;
	list->pyc = y;
	list->pxc = x;
	move_generic(list, movem);
	nbr = ft_itoa(++list->nmov);
	full = ft_strjoin("Move; ", nbr);
	mlx_delete_image(list->mlx, list->img->steps);
	list->img->steps = mlx_put_string(list->mlx, full, 10, 10);
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
	free(full);
	free(nbr);
}

void	character_move(t_list *list, mlx_key_data_t keydata)
{
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_RELEASE)
	{
		movement(list, list->pyc - 1, list->pxc, 0);
		list->img->characterup->enabled = 1;
	}
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_RELEASE)
	{
		movement(list, list->pyc, list->pxc - 1, 1);
		list->img->characterleft->enabled = 1;
	}
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_RELEASE)
	{
		movement(list, list->pyc + 1, list->pxc, 2);
		list->img->characterdown->enabled = 1;
	}
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_RELEASE)
	{
		movement(list, list->pyc, list->pxc + 1, 3);
		list->img->characterright->enabled = 1;
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
	else
		character_move(list, keydata);
}
