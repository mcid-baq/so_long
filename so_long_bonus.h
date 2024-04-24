/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:50:27 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/04/16 18:10:26 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line_bonus.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*collectible;
	mlx_image_t	*characterup;
	mlx_image_t	*characterdown;
	mlx_image_t	*characterleft;
	mlx_image_t	*characterright;
	mlx_image_t	*exitup;
	mlx_image_t	*exitdown;
	mlx_image_t	*enemyright;
	mlx_image_t	*enemyleft;
	mlx_image_t	**anim_frames;
	mlx_image_t	*steps;
}				t_img;

typedef struct s_list
{
	mlx_t		*mlx;
	int			nlines;
	int			llines;
	int			pxc;
	int			pyc;
	int			nmov;
	int			nc;
	int			ccurrent;
	int			np;
	int			ne;
	int			nx;
	char		**sm;
	char		load_anim;
	t_img		*img;

}				t_list;

void			print_error(char *error, t_list *list);
void			fill_bonus(t_list *list, int x, int y);
int				checking_chr_bonus(char *str);
int				fill_works_bonus(t_list *list);
void			free_error(t_list *list);
void			free_map(t_list *list);
void			close_and_print(int m, char *p, t_list *list);
void			key_mv(mlx_key_data_t keydata, void *param);
void			read_map(char **argv, t_list *list);
void			map_painting(t_list *list);
void			painting_enemy(t_list *list);
void			painting2(t_list *list, int y, int x);

#endif