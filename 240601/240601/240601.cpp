#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
//int main()
//{
//	double i = 0;
//	double a = 0;
//	for (i = 0; i < 100; i++)
//	{
//		a = a + (pow(-1.0, i) / (i + 1));
//	}
//	printf("%lf", a);
//
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	int a = 0;
//	int b = 0;
//	for (i = 0; i < 100; i++)
//	{
//		a = (i + 1) % 10;
//		b = (i + 1) / 10;
//		if (a == 9 || b == 9)
//		{
//			count += 1;
//		}
//	}
//	printf("有%d个含有9的数", count);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	printf("1000到2000年");
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
//			printf("%d年 ", i);
//	}
//	printf("是闰年");
//	return 0;
//}
//int main()
//{
//	int i = 2;
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	while (true)
//	{
//		if (i % a == 0 && i % b == 0)
//		{
//			printf("%d和%d的最大公约数是%d", a, b, i);
//			break;
//		}
//		i++;
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int a = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			a = i * j;
//			printf("%d*%d=%d ", i, j, a);
//		}
//	}
//}
//int main() {
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++) {
//		int tag = 1;
//		for (j = 2; j <= i - 1; j++) {
//			if (i % j == 0) {
//				tag = 0;
//				break;
//			}
//		}
//		if (tag == 1) {
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//int main()
//{
//    char str[] = "hello bit";
//    printf("%d %d\n", sizeof(str), strlen(str));
//    return 0;
//}
//int main()
//{
//    int arr[] = { 1,2,(3,4),5 };
//    printf("%d\n", sizeof(arr));
//    return 0;
//}
//int main() {
//	int a = (1, 2, 3, 4);
//	int b = 0;
//	b = 1, 2, 3, 4;
//	printf("a=%d\n", a);
//	printf("b=%d\n", b);
//	return 0;
//}
