/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:09:32 by seyeo             #+#    #+#             */
/*   Updated: 2022/03/15 13:01:47 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src2;
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (0);
	dest = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (i++ < n)
		*dest++ = *src2++;
	return (dst);
}
/* src를 n만큼 size_t바이트를 dst에 복사 (문자열을 복사할 때는 \0까지 생각해야함.(+1))
If dst and src overlap, behavior is undefined.
Applications in which dst and src might overlap
should use memmove(3) instead.*/