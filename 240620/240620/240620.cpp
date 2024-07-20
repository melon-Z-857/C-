#include<stdio.h>
#include<string.h>
#define n 3

////有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
////要求：时间复杂度小于O(N);
//int Find(int arr[n][n], int N, int A) {
//	int flag = 0;
//	int i = 0;
//	for (i = 0; i < N; i++) {
//		if (A < arr[i][i])
//			break;
//		else if (A == arr[i][i])
//			flag = 1;
//	}
//	if (flag == 0) {
//		int j = 0;
//		for (j = 0; j < i; j++) {
//			int k = 0;
//			for (k = i; k < n; k++) {
//				if (A == arr[j][k]) {
//					flag = 1;
//					break;
//				}
//			}
//		}
//	}
//	if (flag == 0) {
//		int j = 0;
//		for (j = i; j < N; j++) {
//			int k = 0;
//			for (k = 0; k < i; k++) {
//				if (A == arr[j][k]) {
//					flag = 1;
//					break;
//				}
//			}
//		}
//	}
//	if (flag == 1)
//		return 1;
//	else
//		return 0;
//}
//int main() {
//	int arr[n][n] = { {1,2,3},{2,3,5},{3,5,6} };
//	int a = 0;
//	scanf_s("%d", &a);
//	Find(arr, n, a);
//	printf("%d\n", Find(arr, n, a));
//
//	return 0;
//}

////日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
////以下为4个嫌疑犯的供词:
////A说：不是我。
////B说：是C。
////C说：是D。
////D说：C在胡说
////已知3个人说了真话，1个人说的是假话。
////现在请根据这些信息，写一个程序来确定到底谁是凶手。
//int test(int arr[4][4], int sz) {
//	int flag = 0;//哪一个是凶手
//	int i = 0;
//	for (i = 0; i < sz; i++) {
//		int arr1[4] = { 1,1,1,1 };//嫌疑人名单，1代表有嫌疑，一开始都有嫌疑，根据陈述置为0，表示一定不是凶手，最后只有1个1和3个0
//		int j = 0;
//		for (j = 0; j < sz; j++) {
//			if (j != i) {
//				int k = 0;
//				for (k = 0; k < sz; k++) {
//					if (arr[j][k] == 0) {
//						arr1[k] = 0;
//					}
//				}
//			}
//		}
//		int count = 0;//凶手个数
//		int l = 0;
//		for (l = 0; l < sz; l++) {
//			if (arr1[l] == 1) {
//				flag = l;
//			}
//			count += arr1[l];
//		}
//		if (count == 1) {
//			return flag;
//		}
//	}
//}
//int main() {
//	int arr[4][4] = { {0,1,1,1},{0,0,1,0},{0,0,0,1},{1,1,1,0} };//4个一维数组分别代表ABCD4个人的陈述，0代表一定不是凶手，1表示可能是
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	test(arr, sz);
//	printf("%d\n", test(arr, sz));
//
//	return 0;
//}

////转移表和回调函数
//void menu() {
//	printf("-------------------------\n");
//	printf("-------1.Add 2.Sub-------\n");
//	printf("-------3.Mul 4.Div-------\n");
//	printf("-------0.Exit------------\n");
//	printf("---------请选择----------\n");
//	printf("-------------------------\n");
//}
//
//int Add(int x, int y) {
//	return (x + y);
//}
//int Sub(int x, int y) {
//	return (x - y);
//}
//int Mul(int x, int y) {
//	return (x * y);
//}
//int Div(int x, int y) {
//	return (x / y);
//}
//int(*pf[5])(int, int) = { 0,Add,Sub,Mul,Div};
//void Calc(int(*pf)(int, int)) {
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数\n");
//	scanf_s("%d %d", &x, &y);
//	printf("%d\n", pf(x, y));
//}
//
//int main() {
//	int input = 0;
//	do {
//		menu();
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 0:
//			break;
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//	}while(input);
//
//	return 0;
//}

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
//例如：
//有数组的元素是：1，2，3，4，5，1，2，3，4，6
//只有5和6只出现1次，要找出5和6.
void Find(int arr[],int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		int flag1 = 0;
		int flag2 = 0;
		int j = 0;
		for (j = 0; j < sz; j++) {
			if (j != i) {
				flag2 = 1;
				if (arr[i] == arr[j]) {
					flag1 = 1;
				}
			}
		}
 		if (flag1 == 0 && flag2 ==1) {
			printf("%d ",arr[i]);
		}
	}
}

int main() {
	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Find(arr,sz);

	return 0;
}