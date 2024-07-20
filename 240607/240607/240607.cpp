#include <stdio.h>
#include <stdbool.h>

////实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
////如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
//void multiplication_table(int a)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= a; i++) {
//		for (j = 1; j <= a; j++) {
//			if(j<=i)
//				printf("%d*%d=%d ", j, i, j * i);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	multiplication_table(9);
//	return 0;
//}
//
//
//bool is_leap_year(int year) {
//	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		return true;
//	else
//		return false;
//}
//int main() {
//	int year = 0;
//	scanf_s("%d", &year);
//	if (is_leap_year(year))
//		printf("%d是闰年", year);
//	else
//		printf("%d不是闰年", year);
//	return 0;
//}
//
//
////实现一个函数is_prime，判断一个数是不是素数。
////利用上面实现的is_prime函数，打印100到200之间的素数。
//bool is_prime(int a) {
//	int i = 0;
//	int tag = 0;
//	for (i = 2; i < a; i++) {
//		if (a % i == 0) {
//			tag = 1;
//			break;
//		}
//	}
//	if (tag == 1)
//		return false;
//	else
//		return true;
//}
//int main() {
//	int i = 0;
//	for (i = 100; i <= 200; i++) {
//		if (is_prime(i))
//			printf("%d ", i);
//	}
//	return 0;
//}


//创建一个整形数组，完成对数组的操作
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。
void init(int arr[]) {
	int i = 0;
	for (i = 0; i < 10; i++) {
		arr[i] = 0;
	}
}

void print(int arr[]) {
	int i = 0;
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[]) {
	int i = 0;
	int temp = 0;
	for (i = 0; i < 5; i++) {
		arr[i] = temp;
		arr[i] = arr[9 - i];
		arr[9 - i] = temp;
	}
}
int main() {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	print(arr);
	reverse(arr);
	print(arr);
	init(arr);
	print(arr);

	return 0;
}