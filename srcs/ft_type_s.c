/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 00:43:11 by seyeo             #+#    #+#             */
/*   Updated: 2022/04/25 21:31:50 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	free_p(char *p)
{
	free(p);
	p = NULL;
}

void	ft_type_s(t_format *fm, t_syntax *syntax)
{
	char	*str;
	char	*tmp;
	int		str_len;

	str = ft_strdup(va_arg(fm->ap, char *));
	if (!str)
		str = ft_strdup("(null)");
	str_len = (int)ft_strlen(str);
	syntax->argument = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!syntax->argument)
		return ;
	ft_strlcpy(syntax->argument, str, str_len + 1);
	if (syntax->precision > -1)
	{
		tmp = syntax->argument;
		syntax->argument = ft_strdupn(tmp, (size_t)syntax->precision);
		free_p(tmp);
	}
	if (!syntax->leftjustify)
		ft_left_padding(&syntax->argument, ' ', syntax->width);
	else
		ft_right_padding(&syntax->argument, ' ', syntax->width);
	syntax->len = ft_strlen(syntax->argument);
	free_p(str);
}
