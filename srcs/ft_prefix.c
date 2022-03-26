/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:15:01 by seyeo             #+#    #+#             */
/*   Updated: 2022/03/23 14:34:55 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prefix_h(t_syntax *syntax)
{
	char	*tmp;

	tmp = syntax->argument;
	if (ft_strchr(syntax->prefix, '#'))
	{
		if (syntax->conversion == 'X')
			syntax->argument = ft_strjoin("0X", tmp);
		if (syntax->conversion == 'x')
			syntax->argument = ft_strjoin("0x", tmp);
		free (tmp);
		tmp = NULL;
	}
}

void	ft_prefix(t_syntax *syntax, int sign)
{
	int	len;

	len = (int)ft_strlen(syntax->argument);
	if (syntax->conversion == 'd' || syntax->conversion == 'i')
	{
		len += 1;
		if (ft_strchr(syntax->prefix, '+') && sign == 1)
			ft_left_padding(&syntax->argument, '+', len);
		else if (ft_strchr(syntax->prefix, ' ') && sign == 1)
			ft_left_padding(&syntax->argument, ' ', len);
		else if (sign == -1)
			ft_left_padding(&syntax->argument, '-', len);
	}
	else if (syntax->conversion == 'x' || syntax->conversion == 'X')
		ft_prefix_h(syntax);
}
