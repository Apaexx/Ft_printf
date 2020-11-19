/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynejmi <ynejmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:27:05 by ynejmi            #+#    #+#             */
/*   Updated: 2020/02/05 18:27:41 by ynejmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count(long n)
{
	int c;

	c = 1;
	while ((n = (n / 10)))
		c++;
	return (c);
}

int		xcount(unsigned long n)
{
	int c;

	c = 1;
	while ((n = (n / 16)))
		c++;
	return (c);
}

char	*rev(char *s, int len)
{
	int		i;
	char	tmp;

	i = -1;
	while (++i < --len)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
	}
	return (s);
}

char	*ft_xtoa(long long n, t_list *arg, int p)
{
	char			*ptr;
	int				len;
	int				i;
	int				u;
	unsigned long	nb;

	u = (arg->kind == 7) ? 32 : 0;
	i = -1;
	nb = p ? (unsigned long)n : (unsigned int)n;
	len = arg->prec >= xcount(nb) ? arg->prec : xcount(nb);
	len = (!(!arg->width && !arg->prec && !n && arg->dott)) * len;
	if (!(ptr = (char*)malloc(len + 1 + (arg->kind == 2 ? 2 : 0))) && ++arg->er)
		return (0);
	while (len--)
		(ptr[++i] = nb % 16 + (((nb % 16) < 10) ? 48 : 87 - u)) && (nb /= 16);
	if ((len = (arg->width && !arg->prec && !n && arg->dott)))
		ptr[i] = ' ';
	if (arg->kind == 2)
		i += filit(&ptr[i], len, arg);
	ptr[++i] = '\0';
	arg->kind = 6;
	return (rev(ptr, i));
}

char	*ft_itoa(int n, t_list *arg, int u)
{
	char			*ptr;
	int				len;
	int				i;
	unsigned int	nb;
	long			nj;

	nj = n;
	arg->kind = 3;
	i = -1;
	nj = u ? (unsigned int)nj : nj;
	len = count(nj);
	nb = nj;
	len = arg->prec >= len ? arg->prec : len;
	len = (!(!arg->width && !arg->prec && !n && arg->dott)) * len;
	if (!(ptr = (char*)malloc(len + 1 + (nj < 0))) && ++arg->er)
		return (0);
	if (nj < 0)
		(ptr[++i] = '-') && (nb *= -1);
	while (len--)
		(ptr[++i] = nb % 10 + '0') && (nb /= 10);
	if (arg->width && !arg->prec && !n && arg->dott)
		ptr[i] = ' ';
	ptr[++i] = '\0';
	return ((nj < 0) ? rev(ptr + 1, i - 1) - 1 : rev(ptr, i));
}
