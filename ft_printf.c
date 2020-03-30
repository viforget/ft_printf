/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:08:47 by viforget          #+#    #+#             */
/*   Updated: 2020/02/28 11:27:34 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	va;
	size_t	s;
	size_t	e;
	size_t	sz;

	s = 0;
	e = 0;
	sz = 0;
	va_start(va, format);
	while (format[e])
	{
		if (format[e] == '%')
		{
			write(1, format + s, e - s);
			e += setfunction(format + e + 1, va, &sz);
			s = e + 1;
		}
		e++;
		sz++;
	}
	write(1, format + s, e - s);
	va_end(va);
	return (sz);
}
