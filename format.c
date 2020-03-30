/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 07:01:59 by viforget          #+#    #+#             */
/*   Updated: 2020/02/28 11:26:55 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_prec(char *src, t_arg arg)
{
	char	*dst;
	int		i;
	int		j;

	i = ft_strlen(src);
	dst = ft_strnew(ft_max(arg.prec, i), '0');
	j = ft_strlen(dst);
	while (i >= 0)
	{
		dst[j] = src[i];
		i--;
		j--;
	}
	free(src);
	return (dst);
}

void	do_src_back(int j, char *dst, char *src, t_arg arg)
{
	int i;

	i = ft_strlen(src);
	while (i >= 0)
		dst[j--] = src[i--];
	while (j > 0 && dst[j] == '0')
		j--;
	if (arg.neg || arg.plus)
		dst[j] = arg.neg ? '-' : '+';
}

char	*ft_format(char *src, t_arg arg)
{
	char	*dst;
	int		i;
	int		j;

	src = ft_prec(src, arg);
	dst = ft_strnew(arg.space, arg.prec > -1 ? ' ' : arg.zero);
	if (arg.minus == 1)
	{
		j = (arg.neg || arg.plus);
		i = 0;
		while (src[i])
			dst[j++] = src[i++];
		if (arg.neg || arg.plus)
			dst[0] = arg.neg ? '-' : PLUS[arg.plus];
	}
	else
		do_src_back(ft_strlen(dst), dst, src, arg);
	free(src);
	return (dst);
}
