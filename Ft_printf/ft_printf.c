/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynejmi <ynejmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:23:51 by ynejmi            #+#    #+#             */
/*   Updated: 2020/02/16 16:20:26 by ynejmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		do_shit(va_list list, t_list *arg)
{
	if ((arg->dott) && arg->kind != 8 && arg->prec >= 0)
		arg->flags = 0;
	if (arg->kind == 8)
		arg->cont = ft_chardup('%', arg);
	else if (arg->kind == 0)
		arg->cont = ft_chardup(va_arg(list, int), arg);
	else if (arg->kind == 5 || arg->kind == 3)
		arg->cont = ft_itoa(va_arg(list, int), arg, 0);
	else if (arg->kind == 4)
		arg->cont = ft_itoa(va_arg(list, unsigned int), arg, 1);
	else if (arg->kind == 1)
		arg->cont = va_arg(list, char *);
	else if (arg->kind == 2)
		arg->cont = ft_xtoa(va_arg(list, size_t), arg, 1);
	else if (arg->kind == 7 || arg->kind == 6)
		arg->cont = ft_xtoa(va_arg(list, unsigned int), arg, 0);
	else
		return (0);
	return (wtreat(arg));
}

int		fill(char *c, va_list list, t_list *arg)
{
	int i;
	int j;

	i = 1;
	while (c[arg->skip] == '-')
	{
		i = -1;
		arg->skip++;
	}
	if (c[arg->skip] == '*')
	{
		j = va_arg(list, int);
		j *= (j < 0 && !arg->dott) ? 1 : i;
	}
	else
		j = i * ft_atoi(c, arg);
	return (j);
}

void	linit(t_list *arg)
{
	arg->flags = 0;
	arg->width = 0;
	arg->er = 0;
	arg->prec = 0;
	arg->dott = 0;
	arg->skip = 0;
}

int		whatisit(char *c, va_list list, t_list *arg)
{
	int i;

	while (ft_strchr("-.*cspiudxX% 0123456789", c[arg->skip]) > -1)
	{
		if (c[arg->skip] == '0')
			arg->flags = 1;
		arg->skip += (i = (c[arg->skip] == '.'));
		arg->dott += i;
		if (ft_isdigit(c[arg->skip]) || c[arg->skip] == '*')
		{
			if (arg->dott)
				arg->prec = fill(c, list, arg);
			else
				arg->width = fill(c, list, arg);
		}
		i = (c[arg->skip] != '%');
		if ((arg->kind = ft_strchr("cspiudxX%", c[arg->skip++])) > -1)
			return (do_shit(list, arg));
	}
	return (-1);
}

int		ft_printf(const char *format, ...)
{
	va_list		list;
	int			i;
	int			j;
	t_list		arg;

	i = 0;
	j = 0;
	va_start(list, format);
	while (format[i])
	{
		linit(&arg);
		if (format[i] != '%')
			j += write(1, &format[i++], 1);
		else if ((j += whatisit((char *)&format[++i], list, &arg)) && arg.er)
			return (-1);
		i += arg.skip;
	}
	va_end(list);
	return (j);
}
