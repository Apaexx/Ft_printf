/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynejmi <ynejmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:02:54 by ynejmi            #+#    #+#             */
/*   Updated: 2020/01/30 12:45:28 by ynejmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_list
{
	int				prec;
	int				dott;
	int				kind;
	int				skip;
	int				flags;
	int				width;
	int				er;
	char			*cont;
}				t_list;

int				vibe_check(t_list *arg);
int				ft_putchar(char c);
int				ft_putarg(char *str, int j, t_list *arg);
int				ft_printf(const char *format, ...);
ssize_t			ft_strchr(char *s, char c);
char			*ft_chardup(char src, t_list *arg);
int				ft_atoi(char *str, t_list *arg);
int				ft_isdigit(int c);
int				ft_strlen(char *str, int j, t_list *arg);
char			*ft_itoa(int n, t_list *arg, int u);
char			*ft_xtoa(long long n, t_list *arg, int p);
int				count(long n);
int				xcount(unsigned long n);
int				wtreat(t_list *arg);
char			*ft_substr(char *s, int start, size_t len);
int				filit(char *ptr, int len, t_list *arg);

#endif
