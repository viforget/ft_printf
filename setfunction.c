/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setfunction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 08:22:08 by viforget          #+#    #+#             */
/*   Updated: 2020/02/28 15:02:33 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_arg	initarg(void)
{
	t_arg arg;

	arg.zero = ' ';
	arg.minus = 0;
	arg.plus = 0;
	arg.neg = 0;
	arg.space = 0;
	arg.prec = -1;
	arg.maj = 0;
	return (arg);
}

int		find_number(const char *format, size_t *e, va_list va)
{
	int nb;

	if (format[*e] == '*')
	{
		(*e)++;
		nb = (va_arg(va, int));
	}
	else
		nb = 0;
	if (ft_isdigit(format[(*e)]) == 1)
		nb = ft_atoi(format + *e);
	while (format[*e] >= '0' && format[*e] <= '9')
	{
		(*e)++;
	}
	return (nb);
}

void	neg_space(t_arg *arg)
{
	arg->zero = ' ';
	arg->minus = 1;
	arg->space *= -1;
}

t_arg	setflag(const char *format, va_list va, size_t *e)
{
	t_arg arg;

	arg = initarg();
	while (ft_strchr("+-0 ", format[*e]))
	{
		if (format[*e] == '-')
			neg_space(&arg);
		else if (format[*e] == '0' && arg.minus == 0)
			arg.zero = '0';
		else if (format[*e] == '+')
			arg.plus = 1;
		else if (format[*e] == ' ')
			arg.plus = 2;
		(*e)++;
	}
	arg.space = find_number(format, e, va);
	if (arg.space < 0)
		neg_space(&arg);
	if (format[*e] == '.')
	{
		(*e)++;
		arg.prec = find_number(format, e, va);
	}
	return (arg);
}

size_t	setfunction(const char *format, va_list va, size_t *sz)
{
	int		i;
	size_t	e;
	t_arg	arg;

	i = 0;
	e = 0;
	arg = setflag(format, va, &e);
	while (BASE[i] && (BASE[i] == '.' || (BASE[i] != format[e] &&
				BASE[i] - 32 != format[e])))
		i++;
	if (format[e] < 'a')
		arg.maj = 1;
	if (BASE[i] != 0)
		*sz += affunumber(arg, (va_arg(va, unsigned int)), i);
	else if (format[e] == 'd' || format[e] == 'i')
		*sz += affsnumber(arg, (va_arg(va, int)), 10);
	else if (format[e] == 's')
		*sz += affstr(arg, va_arg(va, char *));
	else if (format[e] == 'c')
		*sz += affchar(arg, va_arg(va, int));
	else if (format[e] == '%')
		*sz += affchar(arg, '%');
	else if (format[e] == 'p')
		*sz += affadress(arg, (va_arg(va, unsigned long long)));
	return (e + 1);
}
