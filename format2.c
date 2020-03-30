/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 08:37:02 by viforget          #+#    #+#             */
/*   Updated: 2020/02/28 11:42:49 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_prectxt(char *src, t_arg arg)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	if (arg.prec >= 0)
		dst = ft_strnew(ft_min(arg.prec, ft_strlen(src)), ' ');
	else
		dst = ft_strnew(ft_strlen(src), ' ');
	j = 0;
	while (dst[j] && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	free(src);
	return (dst);
}

void	do_txt_back(int j, char *src, char *dst, t_arg arg)
{
	int i;

	i = ft_strlen(src);
	j = ft_strlen(dst);
	while (i >= 0)
		dst[j--] = src[i--];
	if (arg.neg || arg.plus)
		dst[j] = arg.neg ? '-' : '+';
}

char	*ft_formatxt(char *src, t_arg arg)
{
	char	*dst;
	int		i;
	int		j;

	src = ft_prectxt(src, arg);
	arg.space = ft_max(arg.space, ft_strlen(src));
	dst = ft_strnew(arg.space, arg.zero);
	if (arg.minus == 1)
	{
		j = (arg.neg || arg.plus);
		i = 0;
		while (src[i])
			dst[j++] = src[i++];
		if (arg.neg || arg.plus)
			dst[0] = arg.neg ? '-' : '+';
	}
	else
		do_txt_back(ft_strlen(dst), src, dst, arg);
	free(src);
	return (dst);
}
