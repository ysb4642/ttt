/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:15:45 by seyeo             #+#    #+#             */
/*   Updated: 2022/05/14 14:58:31 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_syntax(t_format *fm)
{
	t_syntax	*syntax;

	fm->i++;
	syntax = ft_init_syntax();
	ft_parsing(fm, syntax);
	if (syntax->type)
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
