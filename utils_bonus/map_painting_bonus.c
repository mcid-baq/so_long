/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_painting_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:34:24 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/04/16 18:17:58 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	load_textures(t_list *list, char *l_textures, mlx_image_t **im)
{
	mlx_texture_t	*pix;

	pix = mlx_load_png(l_textures);
	if (!pix)
		return (1);
	*im = mlx_texture_to_image(list->mlx, pix);
	mlx_delete_texture(pix);
	if (!*im)
		return (1);
	return (0);
}

void	load_image2(t_list *list)
{
	if (load_textures(list, "./textures/MainGuyLeft.png",
			&list->img->characterleft))
		print_error("Error texture P", list);
	if (load_textures(list, "./textures/MainGuyRight.png",
			&list->img->characterright))
		print_error("Error texture P", list);
	if (load_textures(list, "./textures/Bear.png", &list->img->enemyright))
		print_error("Error texture X", list);
	if (load_textures(list, "./textures/Bearleft.png", &list->img->enemyleft))
		print_error("Error texture X", list);
	if (load_textures(list, "./textures/Winter_Pine_Tree.png",
			&list->img->wall))
		print_error("Error texture 1", list);
	if (load_textures(list, "./textures/snow_floor.png", &list->img->floor))
		print_error("Error texture 0", list);
}

void	load_image(t_list *list)
{
	if (load_textures(list, "./textures/card.png", &list->img->collectible))
		print_error("Error texture C", list);
	if (load_textures(list, "./textures/Mailboxflagup.png", &list->img->exitup))
		print_error("Error texture E", list);
	if (load_textures(list, "./textures/Mailboxflagdown.png",
			&list->img->exitdown))
		print_error("Error texture E", list);
	if (load_textures(list, "./textures/MainGuyFace.png",
			&list->img->characterdown))
		print_error("Error texture P", list);
	if (load_textures(list, "./textures/MainGuyBack.png",
			&list->img->characterup))
		print_error("Error texture P", list);
	load_image2(list);
}

void	painting(t_list *list)
{
	int	y;
	int	x;

	y = 0;
	while (y < list->nlines)
	{
		x = 0;
		while (x < list->llines)
		{
			painting2(list, y, x);
			x++;
		}
		y++;
	}
}

void	map_painting(t_list *list)
{
	load_image(list);
	painting(list);
	if (mlx_image_to_window(list->mlx, list->img->characterdown, list->pxc * 64,
			list->pyc * 64))
		print_error("Fail to paint the map", list);
	if (mlx_image_to_window(list->mlx, list->img->characterup, list->pxc * 64,
			list->pyc * 64))
		print_error("Fail to paint the map", list);
	if (mlx_image_to_window(list->mlx, list->img->characterleft, list->pxc * 64,
			list->pyc * 64))
		print_error("Fail to paint the map", list);
	if (mlx_image_to_window(list->mlx, list->img->characterright, list->pxc
			* 64, list->pyc * 64))
		print_error("Fail to paint the map", list);
	list->img->characterup->instances[0].enabled = 0;
	list->img->characterleft->instances[0].enabled = 0;
	list->img->characterright->instances[0].enabled = 0;
	list->img->exitup->instances[0].enabled = 0;
}
