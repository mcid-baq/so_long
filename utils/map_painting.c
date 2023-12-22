/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_painting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:34:24 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/22 13:42:20 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	load_image(t_list *list)
{
	if (load_textures(list, "./textures/carta.png", &list->img->collectible))
		print_error("Fallo textura C", list);
	if (load_textures(list, "./textures/Mailboxsprite2_side_lrg.png",
			&list->img->exit))
		print_error("Fallo textura E", list);
	if (load_textures(list, "./textures/MainGuyFaceFront.png",
			&list->img->character))
		print_error("Fallo textura P", list);
	if (load_textures(list, "./textures/Winter_Pine_Tree.png",
			&list->img->wall))
		print_error("Fallo textura 1", list);
	if (load_textures(list, "./textures/snow_floor.png", &list->img->floor))
		print_error("Fallo textura 0", list);
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
			if (mlx_image_to_window(list->mlx, list->img->floor, x * 64, y
					* 64) < 0)
				print_error("Fallo en dibujar suelo", list);
			if (list->sm[y][x] == '1' && mlx_image_to_window(list->mlx,
					list->img->wall, x * 64, y * 64) < 0)
				print_error("Fallo en dibujar muros", list);
			else if (list->sm[y][x] == 'C' && mlx_image_to_window(list->mlx,
						list->img->collectible, x * 64, y * 64) < 0)
				print_error("Fallo en dibujar ventana", list);
			else if (list->sm[y][x] == 'E' && mlx_image_to_window(list->mlx,
						list->img->exit, x * 64, y * 64) < 0)
				print_error("Fallo en dibujar la salida", list);
			x++;
		}
		y++;
	}
}

void	map_painting(t_list *list)
{
	load_image(list);
	painting(list);
	if (mlx_image_to_window(list->mlx, list->img->character, list->pxc * 64,
			list->pyc * 64))
		print_error("Fallo en dibujar el mapa)", list);
}
