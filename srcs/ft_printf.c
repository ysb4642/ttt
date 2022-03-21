/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:24:30 by seyeo             #+#    #+#             */
/*   Updated: 2022/03/18 13:17:17 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_syntax(t_format *fm)
{
	t_syntax	*syntax;

	fm->i++;
	syntax = ft_init_syntax();
	ft_parse(fm, syntax);
	if (syntax->conversion)
	{
		ft_convert_type(fm, syntax);
		fm->len += write(1, syntax->argument, syntax->len);
		free(syntax->argument);
	}
	free(syntax->prefix);
	free(syntax);
	syntax->prefix = NULL;
	syntax = NULL;
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	*fm;
	int			len;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	fm = ft_init_format(format, ap);
	if (!fm)
		return (0);
	while (fm->format[fm->i])
	{
		if (fm->format[fm->i] == '%')
			ft_syntax(fm);
		else
			fm->len += write(1, &fm->format[fm->i++], 1);
	}
	len = fm->len;
	free(fm);
	fm = NULL;
	va_end(ap);
	return (len);
}
