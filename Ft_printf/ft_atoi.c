/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynejmi <ynejmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:27:30 by ynejmi            #+#    #+#             */
/*   Updated: 2020/02/05 18:27:53 by ynejmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str, t_list *arg)
{
	int	a;
	int	s;

	a = 0;
	s = 1;
	if (str[arg->skip] == '-')
		arg->skip -= (s = -1);
	while (ft_isdigit(str[arg->skip]))
	{
		if (a < 0 && s < 0)
			return (0);
		if (a < 0 && s > 0)
			return (-1);
		a = a * 10 + (str[arg->skip++] - '0');
	}
	arg->skip--;
	return (a * s);
}

int		ft_isdigit(int n)
{
	if ((n >= '0' && n <= '9') || n == '-')
		return (1);
	return (0);
}

ssize_t	ft_strchr(char *str, char c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (s[i] != c)
	{
		if (s[i])
			i++;
		else
			return (-1);
	}
	return (i);
}

char	*ft_chardup(char src, t_list *arg)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = malloc(2)) && ++arg->er)
		return (0);
	dest[i] = src;
	i++;
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen(char *str, int j, t_list *arg)
{
	int i;

	i = 0;
	if (str == NULL && arg->kind == 1)
		return (ft_strlen("(null)", j, arg));
	else
	{
		if (!arg->kind)
			i++;
		while (str[i] && j--)
			i++;
	}
	return (i);
}
