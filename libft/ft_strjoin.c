/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:42:58 by seyeo             #+#    #+#             */
/*   Updated: 2022/02/26 20:30:08 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		str_len;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
	{
		if (!(s1))
			return (ft_strdup(s2));
		else
			return (ft_strdup(s1));
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_len = s1_len + s2_len;
	str = (char *)malloc(sizeof(char) * str_len + 1);
	if (!(str))
		return (NULL);
	ft_strlcpy(str + ft_strlcpy(str, s1, s1_len + 1), s2, s2_len + 1);
	return (str);
}
/* #1. 앞에 올 문자열. #2. 뒤에 올 문자열.
반환 값 : 새로운 문자열. 할당 실패시 NULL.
새로운 문자열은 문자열 's1'과 문자열 's2'의 연결된 형태. */
/* ft_strlcpy의 반환값은 2번째 인자(복사하려는 문자열)의 길이 */