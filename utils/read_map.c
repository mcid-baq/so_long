/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:53:00 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/22 13:42:55 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collectibles(char c, t_list *list)
{
	if (c == 'C')
		list->nc++;
	else if (c == 'E')
		list->ne++;
	else if (c == 'P')
		list->np++;
}

void	reading_map_lines(int m, int i, t_list *list)
{
	char	*l;

	l = get_next_line(m);
	while (l)
	{
		if (l[ft_strlen(l) - 1] == '\n')
			l[ft_strlen(l) - 1] = '\0';
		if ((int)ft_strlen(l) != i)
			print_error("Fallo longitud mapa", list);
		if (checking_chr(l) || l[0] != '1' || l[i - 1] != '1')
			print_error("Fallo variables", list);
		i = 0;
		while (l[i] != '\0')
		{
			collectibles(l[i], list);
			i++;
		}
		free(l);
		if (list->ne > 1 || list->np > 1)
			print_error("Fallo mapa!", list);
		list->nlines++;
		l = get_next_line(m);
	}
	if (list->nc < 1 || list->ne != 1 || list->np != 1)
		print_error("Fallo cantidad elementos!!", list);
}

void	saving_map(char **argv, t_list *list)
{
	int	m;
	int	in;

	m = open(argv[1], O_RDONLY);
	list->sm = malloc(sizeof(char *) * (list->nlines + 1));
	if (!list->sm)
		print_error("Fallo mapa", list);
	in = 0;
	while (in < list->nlines)
	{
		list->sm[in] = get_next_line(m);
		if (!list->sm[in])
			print_error("Fallo lista!", list);
		if (list->sm[in][list->llines] == '\n')
			list->sm[in][list->llines] = '\0';
		in++;
	}
	list->sm[list->nlines] = NULL;
	in = 0;
	while (list->sm[list->nlines - 1][in] == '1')
		in++;
	if (list->sm[list->nlines - 1][in] != '\0')
		print_error("Fallo lineas mapa", list);
}

void	character(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	while (list->sm[i])
	{
		j = 0;
		while (list->sm[i][j])
		{
			if (list->sm[i][j] == 'P')
			{
				list->pxc = j;
				list->pyc = i;
			}
			j++;
		}
		i++;
	}
	fill(list, list->pxc, list->pyc);
	if (fill_works(list))
	{
		print_error("No Way Jose!", list);
	}
}

void	read_map(char **argv, t_list *list)
{
	int		i;
	int		m;
	char	*p;

	i = ft_strlen(argv[1]);
	if (i < 5 || ft_strncmp(".ber", argv[1] + (i - 4), 5))
		print_error("Invalid Extension", list);
	m = open(argv[1], O_RDONLY);
	if (m < 0)
		print_error("Can't open file", list);
	p = get_next_line(m);
	if (!p)
		close_and_print(m, NULL, list);
	i = 0;
	while (p[i] == '1')
		i++;
	if (p[i] != '\n' || i < 3)
		close_and_print(m, p, list);
	free(p);
	list->llines = i;
	list->nlines++;
	reading_map_lines(m, i, list);
	saving_map(argv, list);
	character(list);
	close(m);
}
