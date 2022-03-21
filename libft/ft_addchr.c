/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:17 by seyeo             #+#    #+#             */
/*   Updated: 2022/02/26 20:30:03 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addchr(char const *str, char const c)
{
	char	*res;
	size_t	str_len;
	size_t	i;

	i = 0;
	str_len = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (str_len + 2));
	if (!res)
		return (NULL);
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i++] = c;
	res[i] = '\0';
	return (res);
}
