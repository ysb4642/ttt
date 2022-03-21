/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 00:52:21 by seyeo             #+#    #+#             */
/*   Updated: 2022/02/27 00:56:09 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupn(const char *str, size_t i)
{
	char	*res;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len > i)
		len = i;
	res = (char *)malloc(sizeof(char) *(len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, str, len);
	res[len] = '\0';
	return (res);
}
