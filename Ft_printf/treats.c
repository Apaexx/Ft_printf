/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynejmi <ynejmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 22:46:50 by ynejmi            #+#    #+#             */
/*   Updated: 2020/02/12 20:36:13 by ynejmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		wtreat(t_list *arg)
{
	char	i;
	int		j;
	int		k;
	char	*c;

	c = arg->cont;
	i = ' ';
	k = 0;
	if (arg->width < 0)
	{
		arg->width *= -1;
		arg->flags = -1;
	}
	j = (arg->kind == 1 && arg->dott) ? arg->prec : -1;
	(arg->flags == -1) && (k += ft_putarg(arg->cont, j, arg));
	if (arg->width > 0)
	{
		if (arg->flags == 1 && ((k += vibe_check(arg)) || 1))
			i = '0';
		while (arg->width-- > ft_strlen(arg->cont, j, arg))
			k += write(1, &i, 1);
	}
	(arg->flags > -1) && (k += ft_putarg(arg->cont, j, arg));
	arg->kind != 1 ? free(c) : 0;
	return (k);
}

int		vibe_check(t_list *arg)
{
	if (arg->kind == 3 && *arg->cont == '-')
	{
		arg->width -= 1;
		return (write(1, arg->cont++, 1));
	}
	return (0);
}

int		filit(char *ptr, int len, t_list *arg)
{
	int i;

	i = 0;
	if (len && (arg->width > 0))
		i = -1;
	ptr[++i] = 'x';
	ptr[++i] = '0';
	if (len && (arg->width > 1))
		ptr[++i] = ' ';
	return (i);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putarg(char *str, int j, t_list *arg)
{
	int i;

	i = 0;
	if (str == NULL && arg->kind == 1)
		return (ft_putarg("(null)", j, arg));
	else
	{
		if (!arg->kind)
			ft_putchar(str[i++]);
		while (str[i] && j--)
			ft_putchar(str[i++]);
	}
	return (i);
}
