/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:13:24 by viforget          #+#    #+#             */
/*   Updated: 2020/02/28 16:22:18 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** INCLUDE
*/

# include <stdarg.h>
# include "../libft/libft.h"

/*
**	DEFINE
*/

# define BASE "..b.....o.u.....x"
# define SYMB "0123456789abcdef"
# define PLUS ".+ "

/*
** STRUCTURE
*/

typedef	struct	s_arg
{
	char		zero;
	char		minus;
	int			plus;
	char		neg;
	int			space;
	int			prec;
	char		maj;
}				t_arg;

/*
** FORMAT.C
*/

char			*ft_format(char *src, t_arg arg);

/*
** FORMAT2.C
*/

char			*ft_formatxt(char *src, t_arg arg);

/*
** FORMATP.C
*/

char			*ft_formatp(char *src, t_arg arg);
/*
** SETFUNCTION.C
*/

size_t			setfunction(const char *format, va_list va, size_t *sz);

/*
** SETTXT.C
*/

size_t			affstr(t_arg arg, char *str);
size_t			affchar(t_arg arg, char c);

/*
** FT_PRINTF.C
*/

int				ft_printf(const char *format, ...);

/*
** SETNUMBER.C
*/

size_t			affunumber(t_arg arg, unsigned int n, int base);
size_t			affsnumber(t_arg arg, int n, int base);
size_t			affadress(t_arg arg, unsigned long long n);

#endif
