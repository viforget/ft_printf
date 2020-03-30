/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settxt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:23:10 by viforget          #+#    #+#             */
/*   Updated: 2020/02/28 14:48:47 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

size_t	affstr(t_arg arg, char *str)
{
	size_t nb;

	if (arg.minus)
		arg.zero = ' ';
	arg.plus = 0;
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	str = ft_formatxt(str, arg);
	nb = ft_putstr(str);
	free(str);
	return (nb - 1);
}

size_t	affchar(t_arg arg, char c)
{
	char	c2[2];
	char	*s;

	c2[0] = c;
	if (arg.space == 0)
		arg.space = 1;
	arg.prec = 1;
	if (c == '\0')
	{
		s = ft_strnew(arg.space - 1, ' ');
		if (arg.minus == 0)
		{
			write(1, s, arg.space);
			free(s);
		}
		else
		{
			write(1, "\0", 1);
			ft_putstr(s);
			free(s);
		}
	}
	else
		affstr(arg, c2);
	return (arg.space - 1);
}
