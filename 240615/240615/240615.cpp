#include <stdio.h>


////求第n个斐波那契数
//int Fib1(int n) {
//	if (n <= 2)
//		return 1;
//	else
//		return (Fib1(n - 1) + Fib1(n - 2));
//}
//
//int Fib2(int n) {
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2) {
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main() {
//	int n = 0;
//	scanf_s("%d", &n);
//	printf("%d %d", Fib1(n), Fib2(n));
//
//	return 0;
//}
//
//
////求n的k次方
//int pow(int n, int k) {
//	if (k > 1)
//		return (n * pow(n, k - 1));
//	else
//		return n;
//}
//
//int main() {
//	int n = 0;
//	int k = 0;
//	scanf_s("%d %d", &n, &k);
//	printf("%d的%d次方是%d\n", n, k, pow(n, k));
//
//	return 0;
//}
//
//
////计算一个数的每位之和
//int DigitSum(int n) {
//	if (n / 10 != 0)
//		return ((n % 10) + DigitSum(n / 10));
//	else
//		return n;
//}
//
//int main() {
//	int n = 0;
//	scanf_s("%d", &n);
//	printf("%d的每一位之和是%d", n, DigitSum(n));
//
//	return 0;
//}
//
////求n的阶乘
//int F1(int n) {
//	if (n != 0)
//		return (n * F1(n - 1));
//	else
//		return 1;
//}
//
//int F2(int n) {
//	int a = 1;
//	while (n>0)
//	{
//		a *= n;
//		n--;
//	}
//	return a;
//}
//
//
//int main() {
//	int n = 0;
//	scanf_s("%d", &n);
//	printf("%d的阶乘是%d\n", n, F1(n));
//	printf("%d的阶乘是%d\n", n, F2(n));
//
//	return 0;
//}


void print(int n) {
	if (n / 10 != 0) {
		print(n / 10);
		printf("%d ", (n % 10));
	}
	else {
		printf("%d ", n);
	}
}

int main() {
	int n = 0;
	scanf_s("%d", &n);
	print(n);

	return 0;
}