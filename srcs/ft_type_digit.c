/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 00:59:17 by seyeo             #+#    #+#             */
/*   Updated: 2022/04/25 21:31:52 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_digit(t_format *fm, t_syntax *syntax, char *base)
{
	unsigned int	num;

	num = (unsigned int)(va_arg(fm->ap, unsigned int));
	syntax->argument = ft_printf_itoa((unsigned long)num, base);
	if (syntax->precision > -1)
	{
		if (!syntax->precision && num == 0)
		{
			free(syntax->argument);
			syntax->argument = ft_strdup("");
		}
		ft_left_padding(&syntax->argument, '0', syntax->precision);
		syntax->pad = ' ';
	}
	if (num)
		ft_prefix(syntax, 0);
	if (!syntax->leftjustify)
		ft_left_padding(&syntax->argument, syntax->pad, syntax->width);
	else
		ft_right_padding(&syntax->argument, ' ', syntax->width);
	syntax->len = ft_strlen(syntax->argument);
}
