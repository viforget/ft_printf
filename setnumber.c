/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setnumber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:14:50 by viforget          #+#    #+#             */
/*   Updated: 2020/02/28 14:49:47 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*alt_itoa_base(unsigned int n, unsigned int base)
{
	int				ct;
	unsigned int	n2;
	char			*s;

	ct = 1;
	n2 = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (n2 >= base)
	{
		n2 /= base;
		ct++;
	}
	if (!(s = ft_calloc(ct + 1, 1)))
		return (NULL);
	while (n > 0)
	{
		ct--;
		s[ct] = SYMB[n % base];
		n /= base;
	}
	return (s);
}

char	*alt_itoa_base_lg(unsigned long long n, unsigned int base)
{
	int					ct;
	unsigned long long	n2;
	char				*s;

	ct = 1;
	n2 = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (n2 >= base)
	{
		n2 /= base;
		ct++;
	}
	if (!(s = ft_calloc(ct + 1, 1)))
		return (NULL);
	if (n == 0)
		s[0] = 0;
	while (n > 0)
	{
		ct--;
		s[ct] = SYMB[n % base];
		n /= base;
	}
	return (s);
}

size_t	affunumber(t_arg arg, unsigned int n, int base)
{
	char	*num;
	char	*anum;
	size_t	sz;

	if (arg.minus)
		arg.zero = ' ';
	if (n == 0 && arg.prec == 0)
		num = ft_strdup("");
	else
		num = alt_itoa_base(n, base);
	if (arg.maj == 1)
		num = ft_to_up(num);
	arg.space = ft_max(ft_strlen(num) + (arg.neg || arg.plus), arg.space);
	arg.space = ft_max(arg.space, arg.prec);
	anum = ft_format(num, arg);
	sz = ft_putstr(anum);
	free(anum);
	return (sz - 1);
}

size_t	affsnumber(t_arg arg, int n, int base)
{
	char	*num;
	size_t	sz;

	if (n < 0)
	{
		arg.neg = 1;
		n *= -1;
	}
	if (n == 0 && arg.prec == 0)
		num = ft_strdup("");
	else
		num = alt_itoa_base(n, base);
	if (arg.maj == 1)
		num = ft_to_up(num);
	arg.space = ft_max(ft_strlen(num) + (arg.neg || arg.plus), arg.space);
	arg.space = ft_max(arg.space, arg.prec + (arg.neg || arg.plus));
	num = ft_format(num, arg);
	sz = ft_putstr(num);
	free(num);
	return (sz - 1);
}

size_t	affadress(t_arg arg, unsigned long long n)
{
	char	*num;
	size_t	sz;

	if (n == 0 && arg.prec == 0)
		num = ft_strdup("");
	else
		num = alt_itoa_base_lg(n, 16);
	arg.space = ft_max(ft_strlen(num) + 2, arg.space);
	arg.space = ft_max(arg.space, arg.prec + 2);
	num = ft_formatp(num, arg);
	sz = ft_putstr(num);
	free(num);
	return (sz - 1);
}
