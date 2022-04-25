/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:16:36 by seyeo             #+#    #+#             */
/*   Updated: 2022/04/25 20:42:23 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_init_format(const char *format, va_list ap)
{
	t_format	*fm;

	fm = (t_format *)malloc(sizeof(t_format));
	if (!fm)
		return (NULL);
	fm->format = format;
	va_copy(fm->ap, ap);
	fm->i = 0;
	fm->len = 0;
	return (fm);
}

t_syntax	*ft_init_syntax(void)
{
	t_syntax	*syntax;

	syntax = (t_syntax *)malloc(sizeof(t_syntax));
	if (!syntax)
		return (NULL);
	syntax->argument = NULL;
	syntax->type = '\0';
	syntax->leftjustify = 0;
	syntax->len = 0;
	syntax->pad = ' ';
	syntax->precision = -1;
	syntax->prefix = ft_strdup("");
	syntax->width = 0;
	return (syntax);
}
