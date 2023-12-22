/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:34:43 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/22 13:48:30 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	ft_leaks(void)
{
	system("leaks so_long");
	atexit(ft_leaks);
} */
t_list	*init_value(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		print_error("ERROR MEMORIA LISTA\n", NULL);
	list->img = malloc(sizeof(t_img));
	if (!list->img)
		print_error("ERROR MEMORIA IMG\n", list);
	list->nc = 0;
	list->ne = 0;
	list->np = 0;
	list->nlines = 0;
	list->nmov = 0;
	list->ccurrent = 0;
	list->sm = NULL;
	list->mlx = NULL;
	return (list);
}

int32_t	main(int argc, char **argv)
{
	t_list	*list;

	if (argc != 2)
	{
		printf("ERROR, Invalid number of arguments\n");
		return (0);
	}
	list = init_value();
	read_map(argv, list);
	list->mlx = mlx_init(list->llines * 64, list->nlines * 64, "SO_LONG",
			false);
	if (!list->mlx)
		print_error("Fallo iniciar ventana juego\n", list);
	map_painting(list);
	mlx_key_hook(list->mlx, key_mv, list);
	mlx_loop(list->mlx);
	return (0);
}
