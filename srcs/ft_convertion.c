/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:00:44 by seyeo             #+#    #+#             */
/*   Updated: 2022/03/18 13:13:33 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_type(t_format *fm, t_syntax *syntax)
{
	if (syntax->conversion == 'c')
		ft_conversion_c(fm, syntax);
	else if (syntax->conversion == 's')
		ft_conversion_s(fm, syntax);
	else if (syntax->conversion == 'p')
		ft_conversion_p(fm, syntax);
	else if (syntax->conversion == 'd' || syntax->conversion == 'i')
		ft_conversion_id(fm, syntax);
	else if (syntax->conversion == 'u')
		ft_conversion_digit(fm, syntax, DECIMAL);
	else if (syntax->conversion == 'x')
		ft_conversion_digit(fm, syntax, HEX_L);
	else if (syntax->conversion == 'X')
		ft_conversion_digit(fm, syntax, HEX_U);
	else
		ft_conversion_percent(syntax);
}
