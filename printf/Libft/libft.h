/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:16:33 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/22 13:56:20 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_lb
{
	void		*content;
	struct s_lb	*next;
}		t_lb;

int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
size_t	ft_strlen(const char *str);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *sourc, size_t leng);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *sourc, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *first, const char *second, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *str1, char const *set);
char	*ft_strmapi(char const *a, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);
t_lb	*ft_lstnew_bonus(void *content);
void	ft_lstadd_front_bonus(t_lb **lst, t_lb *new);
t_lb	*ft_lstlast_bonus(t_lb *lst);
void	ft_lstdelone_bonus(t_lb *lst, void (*del)(void *));
void	ft_lstclear_bonus(t_lb **lst, void (*del)(void *));
void	ft_lstadd_back_bonus(t_lb **lst, t_lb *new);
int		ft_lstsize_bonus(t_lb *lst);
t_lb	*ft_lstmap_bonus(t_lb *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter_bonus(t_lb *lst, void (*f)(void *));

#endif