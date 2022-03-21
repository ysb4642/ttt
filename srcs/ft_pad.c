/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:25:28 by seyeo             #+#    #+#             */
/*   Updated: 2022/02/27 20:23:36 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_left_padding(char **str, char pad, int width)
{
	char	*tmp;
	size_t	str_len;
	size_t	pad_len;

	str_len = ft_strlen(*str);
	if (!width || width < (int)str_len)
		width = str_len;
	tmp = (char *)malloc(sizeof(char) * width);
	if (!tmp)
		return ;
	pad_len = width - str_len;
	ft_memset(tmp, pad, pad_len);
	tmp[pad_len] = '\0';
	ft_strlcat(tmp, *str, width + 1);
	free(*str);
	*str = tmp;
}

void	ft_right_padding(char **str, char pad, int width)
{
	char	*tmp;
	size_t	str_len;
	size_t	pad_len;

	str_len = ft_strlen(*str);
	if (!width || width < (int)str_len)
		width = str_len;
	tmp = (char *)malloc(sizeof(char) * width);
	if (!tmp)
		return ;
	ft_strlcpy(tmp, *str, str_len + 1);
	pad_len = width - str_len;
	ft_memset(&tmp[str_len], pad, pad_len);
	tmp[width] = '\0';
	free(*str);
	*str = tmp;
}
