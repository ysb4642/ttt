/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 00:27:23 by seyeo             #+#    #+#             */
/*   Updated: 2022/03/18 13:12:23 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_make_num(t_syntax *syntax)
{
	char	*res;

	if (syntax->precision > -1)
	{
		res = (char *)malloc(sizeof(char) * (syntax->precision + 1));
		if (!res)
			return (NULL);
		ft_memset(res, '0', (size_t)syntax->precision);
		res[syntax->precision] = '\0';
	}
	else
		res = ft_strdup("0");
	return (res);
}

void	ft_conversion_p(t_format *fm, t_syntax *syntax)
{
	void	*p;
	char	*ad;

	ad = NULL;
	p = va_arg(fm->ap, void *);
	if (!p)
		ad = ft_make_num(syntax);
	else
		ad = ft_printf_itoa((unsigned long)p, HEX_L);
	syntax->argument = ft_strjoin("0x", ad);
	free(ad);
	ad = NULL;
	if (!syntax->leftjustify)
		ft_left_padding(&syntax->argument, ' ', syntax->width);
	else
		ft_right_padding(&syntax->argument, ' ', syntax->width);
	syntax->len = ft_strlen(syntax->argument);
}
