/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:24:30 by seyeo             #+#    #+#             */
/*   Updated: 2022/04/13 22:26:06 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
