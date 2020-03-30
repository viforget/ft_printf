/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:35:57 by viforget          #+#    #+#             */
/*   Updated: 2020/02/28 11:34:27 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_precp(char *src, t_arg arg)
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

void	do_adr_back(int j, char *dst, char *src, char zero)
{
	int i;

	i = ft_strlen(src);
	while (i >= 0)
		dst[j--] = src[i--];
	if (zero == '0')
		while (j > 1)
			dst[j--] = '0';
	dst[j > 1 ? j : 1] = 'x';
	dst[j > 1 ? j - 1 : 0] = '0';
}

char	*ft_formatp(char *src, t_arg arg)
{
	char	*dst;
	int		i;
	int		j;

	src = ft_precp(src, arg);
	dst = ft_strnew(arg.space, arg.zero);
	if (arg.minus == 1 && arg.zero != '0')
	{
		j = 2;
		i = 0;
		while (src[i])
			dst[j++] = src[i++];
		dst[0] = '0';
		dst[1] = 'x';
	}
	else
		do_adr_back(ft_strlen(dst), dst, src, arg.zero);
	free(src);
	return (dst);
}
