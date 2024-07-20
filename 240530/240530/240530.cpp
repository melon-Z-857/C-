#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//printf("hello world");
	//int i = 1;
	//for (i; i <= 100; i++)
	//	if (i % 3 == 0)
	//		printf("%d ", i);
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d %d %d", &a, &b, &c);
	if (a > b > c)
		printf("%d %d %d", a, b, c);
	else if (a > c > b)
		printf("%d %d %d", a, c, b);
	else if (b > a > c)
		printf("%d %d %d", b, a, c);
	else if (b > c > a)
		printf("%d %d %d", b, c, a);
	else if (c > a > b)
		printf("%d %d %d", c, a, b);
	else if (c > b > a)
		printf("%d %d %d", c, b, a);
	return 0;
}