/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:50:06 by seyeo             #+#    #+#             */
/*   Updated: 2022/04/25 21:31:50 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_percent(t_syntax *syntax)
{
	syntax->argument = ft_addchr("", syntax->type);
	if (!syntax->leftjustify)
		ft_left_padding(&syntax->argument, syntax->pad, syntax->width);
	else
		ft_right_padding(&syntax->argument, ' ', syntax->width);
	syntax->len = ft_strlen(syntax->argument);
}
