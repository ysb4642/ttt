/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 00:01:05 by seyeo             #+#    #+#             */
/*   Updated: 2022/02/27 00:14:22 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_len(unsigned long num, size_t base_len)
{
	if (num / base_len == 0)
		return (1);
	else
		return (ft_num_len(num / base_len, base_len) + 1);
}

static void	ft_base(unsigned long num, char *res, char *base, size_t i)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (num >= (unsigned long)base_len)
		ft_base((num / base_len), res, base, i - 1);
	res[i] = base[num % base_len];
}

char	*ft_printf_itoa(unsigned long num, char *base)
{
	size_t	num_len;
	size_t	base_len;
	char	*res;

	base_len = ft_strlen(base);
	num_len = ft_num_len(num, base_len);
	res = (char *)malloc(sizeof(char) * (num_len + 1));
	if (!res)
		return (NULL);
	res[num_len--] = '\0';
	ft_base(num, res, base, num_len);
	return (res);
}
