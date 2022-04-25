/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:00:44 by seyeo             #+#    #+#             */
/*   Updated: 2022/04/25 21:31:49 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_type(t_format *fm, t_syntax *syntax)
{
	if (syntax->type == 'c')
		ft_type_c(fm, syntax);
	else if (syntax->type == 's')
		ft_type_s(fm, syntax);
	else if (syntax->type == 'p')
		ft_type_p(fm, syntax);
	else if (syntax->type == 'd' || syntax->type == 'i')
		ft_type_id(fm, syntax);
	else if (syntax->type == 'u')
		ft_type_digit(fm, syntax, DECIMAL);
	else if (syntax->type == 'x')
		ft_type_digit(fm, syntax, HEX_L);
	else if (syntax->type == 'X')
		ft_type_digit(fm, syntax, HEX_U);
	else
		ft_type_percent(syntax);
}
