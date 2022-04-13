/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:45:59 by seyeo             #+#    #+#             */
/*   Updated: 2022/04/13 21:46:46 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(t_format *fm, t_syntax *syntax)
{
	char	*tmp;

	if (!syntax->prefix)
		syntax->prefix = ft_strdup("");
	while (ft_strchr("-+ 0#", fm->format[fm->i]))
	{
		if (fm->format[fm->i] == '-')
			syntax->leftjustify = 1;
		if (ft_strchr("# +", fm->format[fm->i]))
		{
			tmp = syntax->prefix;
			syntax->prefix = ft_addchr(tmp, fm->format[fm->i]);
			free(tmp);
			tmp = NULL;
		}
		if (fm->format[fm->i] == '0')
			syntax->pad = '0';
		fm->i++;
	}
}

void	ft_width(t_format *fm, t_syntax *syntax)
{
	if (ft_isdigit(fm->format[fm->i]))
	{
		syntax->width = 0;
		while (ft_isdigit(fm->format[fm->i]))
		{
			syntax->width = (syntax->width * 10) + (fm->format[fm->i] - 48);
			fm->i++;
		}
	}
}

void	ft_precision(t_format *fm, t_syntax *syntax)
{
	if (fm->format[fm->i] == '.')
	{
		fm->i++;
		if (!ft_isdigit(fm->format[fm->i]))
			syntax->precision = 0;
		else
		{
			syntax->precision = 0;
			while (ft_isdigit(fm->format[fm->i]))
			{
				syntax->precision = (syntax->precision * 10) \
									+ (fm->format[fm->i] - 48);
				fm->i++;
			}
		}
	}
}

void	ft_convert_parsing(t_format *fm, t_syntax *syntax)
{
	if (!ft_strchr(FLAGS, fm->format[fm->i]) \
		&& ft_isprint(fm->format[fm->i]))
	{
		syntax->conversion = fm->format[fm->i];
		fm->i++;
	}
}

void	*ft_parsing(t_format *fm, t_syntax *syntax)
{
	ft_flags(fm, syntax);
	ft_width(fm, syntax);
	ft_precision(fm, syntax);
	ft_convert_parsing(fm, syntax);
	if (!syntax->conversion && (ft_strchr(FLAGS, fm->format[fm->i])))
		ft_parsing(fm, syntax);
	return (syntax);
}
