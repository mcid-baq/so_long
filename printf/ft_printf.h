/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:10:40 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/21 12:22:33 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "Libft/libft.h"

int	ft_printf(char const *str, ...);
int	ft_printchar(char c);
int	ft_printhex(unsigned long p, char *x);
int	ft_printnbr(int n);
int	ft_printstr(char *str);
int	ft_printunsignbr(unsigned int nb);

#endif