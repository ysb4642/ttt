#include "./include/ft_printf.h"
#include <stdio.h>

int main(void) 
{

	char *s1 = NULL;
	char *s2 = "hello";

	ft_printf("%d\n", 10);
	printf("%d\n", 10);

	ft_printf("%+d\n", -10);
	printf("%+d\n", -10);

	ft_printf("% d\n", 10);
	printf("% d\n", 10);

	ft_printf("%#x\n", 10);
	printf("%#x\n", 10);

	ft_printf("%s\n", "hello world");
	printf("%s\n", "hello world");

	ft_printf("%s\n", "안녕하세요");
	printf("%s\n", "안녕하세요");

	ft_printf("%s\n", s1);
	printf("%s\n", s1);

	ft_printf("%p\n", s2);
	printf("%p\n", s2);

	ft_printf("%%\n");
	printf("%%\n");

	ft_printf("%c\n", 'a');
	printf("%c\n", 'a');

}