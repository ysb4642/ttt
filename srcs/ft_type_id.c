/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:55:02 by seyeo             #+#    #+#             */
/*   Updated: 2022/04/25 21:31:51 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_id_width(t_syntax *syntax, int sign)
{
	if (syntax->leftjustify)
	{
		ft_prefix(syntax, sign);
		ft_right_padding(&syntax->argument, ' ', syntax->width);
	}
	else
	{
		if (syntax->pad == ' ')
		{
			ft_prefix(syntax, sign);
			ft_left_padding(&syntax->argument, syntax->pad, syntax->width);
		}
		else if (syntax->pad == '0')
		{
			if (sign < 0 || ft_strchr(syntax->prefix, ' ') || \
					ft_strchr(syntax->prefix, '+'))
				ft_left_padding(&syntax->argument, syntax->pad, \
									syntax->width - 1);
			else
				ft_left_padding(&syntax->argument, syntax->pad, syntax->width);
			ft_prefix(syntax, sign);
		}
	}
}

void	ft_type_id(t_format *fm, t_syntax *syntax)
{
	long	tmp;
	int		sign;

	tmp = (int)va_arg(fm->ap, int);
	sign = 1;
	if (tmp < 0)
		sign *= -1;
	syntax->argument = ft_printf_itoa(tmp * sign, DECIMAL);
	if (syntax->precision > -1)
	{
		if (!syntax->precision && tmp == 0)
		{
			free (syntax->argument);
			syntax->argument = ft_strdup("");
		}
		ft_left_padding(&syntax->argument, '0', syntax->precision);
		syntax->pad = ' ';
	}
	ft_id_width(syntax, sign);
	syntax->len = ft_strlen(syntax->argument);
}
