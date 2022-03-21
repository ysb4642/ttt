/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:36:20 by seyeo             #+#    #+#             */
/*   Updated: 2022/03/18 13:10:35 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion_c(t_format *fm, t_syntax *syntax)
{
	char	c;

	c = (wint_t)va_arg(fm->ap, wint_t);
	if (!syntax->width)
		syntax->width++;
	syntax->argument = (char *)malloc(sizeof(char) * syntax->width);
	if (!syntax->argument)
		return ;
	ft_memset(syntax->argument, ' ', syntax->width);
	if (syntax->leftjustify == 1)
		syntax->argument[0] = c;
	else
		syntax->argument[syntax->width - 1] = c;
	syntax->len = syntax->width;
}
