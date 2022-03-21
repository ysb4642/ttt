/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:45:18 by seyeo             #+#    #+#             */
/*   Updated: 2022/03/15 13:03:40 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dstsize < dst_len + 1)
		return (dstsize + src_len);
	while (src[i] != '\0' && dstsize > dst_len + 1 + i)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
/* 문자열 src를 dst의 끝에(\0 자리부터 )최대 dstsize - strlen(dst) - 1자가 추가됨.
dstsize에는 dst_len보다 큰 값이 들어가야 src에서 덧붙히는게 가능함.(return dstsize + src_len)*/
