#include <stdio.h>


////在一个整型数组中，只有一个数字出现一次，其他数组都是成对出现的，请找出那个只出现一次的数字。
////例如：数组中有：1 2 3 4 5 1 2 3 4，只有5出现一次，其他数字都出现2次，找出5
//int main() {
//	int arr[9] = { 1,2,3,4,5,1,2,3,4 };
//	int i = 0;
//	int flag1 = 1;//有重复的数flag置为1
//	for (i = 0; i < 9; i++) {
//		int j = 0;
//		for (j = 0; j < 9; j++) {
//			if (i != j) {
//				if ((arr[i] ^ arr[j]) == 0) {
//					flag1 = 1;
//				}
//			}
//			else
//				flag1 = 0;
//		}
//		if (flag1 == 0 ) {
//			printf("%d只出现了一次\n", arr[i]);
//			break;
//		}
//	}
//
//	return 0;
//}

////不允许创建临时变量，交换两个整数的内容
//int main() {
//	int a = 3;
//	int b = 4;
//	printf("交换前a=%d b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("交换后a=%d b=%d\n", a, b);
//
//	return 0;
//}

////获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
//void F(int n, int a) {
//	int i = 30;
//	for (i=i+a; i >= 0 + a; i=i - 2) {
//		printf("%d", (n >> i) & 1);
//	}
//}
//
//int main() {
//	int n = 0;
//	scanf_s("%d", &n);
//	printf("%d二进制奇数位为\n", n );
//	F(n, 0);
//	printf("\n");
//	printf("%d二进制偶数位为\n", n );
//	F(n, 1);
//	printf("\n");
//
//	return 0;
//}

