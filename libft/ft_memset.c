/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:10:51 by seyeo             #+#    #+#             */
/*   Updated: 2022/03/15 13:00:59 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;
	unsigned char	src;
	size_t			i;

	dest = b;
	src = c;
	i = 0;
	while (i++ < len)
		*dest++ = src;
	return (b);
}
/* 메모리 주소값 b를 시작으로 len만큼 size_t바이트를 c로 채움
두번째 인자 int형은 내부적으로 unsigned char형으로 바뀜 */
/* 두번째 인자 c는 int 타입으로 받지만 내부에서는 unsigned char 로 변환되어서 저장.
즉 'a' 이런것을 넣어도 무방
세번째 인자 size_t num은 길이.(바이트 단위로써 메모리의 크기 한조각 단위의 길이)
"sizeof(데이터타입)*길이" 의 형태로 작성 */
/*** 0이 아닌 int 타입의 숫자를 넣게되면 예상할 수 없는 값으로 세팅 됨.
그 이유는 memset 함수는 1 바이트 단위로 값을 초기화 하기 때문.
1바이트 단위로 1를 만들었기 때문에 4바이트로 표현된 int 숫자 1은 제대로된 숫자로 표현될 수 없음. 
0은 4바이트든 1바이트든 0 이기 때문에 동일한 결과값이 나옴.
결론적으로 0이아닌 그리고 char 타입이 아닌 값을 넣어서 세팅 하려고 할때는 원하는 값으로 세팅할수 없음.
즉, 0이랑 char 타입만 사용해야함.
그렇기 때문에 memset 함수는 보통 문자열(char 배열)에서 값을 변경하거나, 숫자배열을 0으로 세팅할때 사용함 ***/