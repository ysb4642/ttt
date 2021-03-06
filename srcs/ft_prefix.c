/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:15:01 by seyeo             #+#    #+#             */
/*   Updated: 2022/04/25 21:31:54 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prefix_h(t_syntax *syntax)
{
	char	*tmp;

	tmp = syntax->argument;
	if (ft_strchr(syntax->prefix, '#'))
	{
		if (syntax->type == 'X')
			syntax->argument = ft_strjoin("0X", tmp);
		if (syntax->type == 'x')
			syntax->argument = ft_strjoin("0x", tmp);
		free (tmp);
		tmp = NULL;
	}
}

void	ft_prefix(t_syntax *syntax, int sign)
{
	int	len;

	len = (int)ft_strlen(syntax->argument);
	if (syntax->type == 'd' || syntax->type == 'i')
	{
		len += 1;
		if (ft_strchr(syntax->prefix, '+') && sign == 1)
			ft_left_padding(&syntax->argument, '+', len);
		else if (ft_strchr(syntax->prefix, ' ') && sign == 1)
			ft_left_padding(&syntax->argument, ' ', len);
		else if (sign == -1)
			ft_left_padding(&syntax->argument, '-', len);
	}
	else if (syntax->type == 'x' || syntax->type == 'X')
		ft_prefix_h(syntax);
}
