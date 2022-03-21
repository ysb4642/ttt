/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:44:39 by seyeo             #+#    #+#             */
/*   Updated: 2022/03/15 13:04:08 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len_s2;

	if (!s1)
		return (NULL);
	len_s2 = ft_strlen((char *)s1);
	s2 = (char *)malloc(sizeof(char) * (len_s2 + 1));
	if (!(s2))
		return (NULL);
	ft_memcpy(s2, s1, len_s2);
	s2[len_s2] = '\0';
	return (s2);
}
/* 문자열 s1을 복사하고 복사된 문자열을 가리키는 포인터를 반환,
문자열을 복사할 공간을 확보하기 위해서 내부적으로 malloc이 호출됨*/