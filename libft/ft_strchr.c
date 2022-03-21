/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:54:37 by seyeo             #+#    #+#             */
/*   Updated: 2022/02/26 20:30:07 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	s_len;

	i = 0;
	s_len = ft_strlen(s);
	while (i <= s_len)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
/* s문자열에서 c가 존재하는지 검사하고 문자가 존재하면 해당 문자가 존재하는 곳의 포인터를 반환,
존재하지 않으면 널포인터 반환*/
/* i를 s_len까지 검사해주는 이유 : '\0'까지 검사 */