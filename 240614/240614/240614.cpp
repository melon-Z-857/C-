#include <stdio.h>


//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）
//这个函数中a是瓶子个数，每次除以2，就是续杯的汽水数，如果余1,那么续杯后的瓶子个数就是续杯数加1，只有瓶子个数大于2才能续杯
//int MostDrink(int a) {
//	int i = 0;
//	int sum = a;
//	while (a>=2) {
//		if (a % 2 == 1) {
//			a = a / 2;
//			sum += a;
//			a += 1;
//		}
//		else {
//			a = a / 2;
//			sum += a;
//		}
//	}
//	return sum;
//}
//int main() {
//	int a = 0;
//	printf("输入买汽水的钱数\n");
//	scanf_s("%d", &a);
//	printf("%d元钱最多可以喝%d瓶汽水\n", a, MostDrink(a));
//	return 0;
//}
//
// 
// 
// 
//
//int main() {
//	printf("      *      \n");
//	printf("     ***     \n");
//	printf("    *****    \n");
//	printf("   *******   \n");
//	printf("  *********  \n");
//	printf(" *********** \n");
//	printf("*************\n");
//	printf(" *********** \n");
//	printf("  *********  \n");
//	printf("   *******   \n");
//	printf("    *****    \n");
//	printf("     ***     \n");
//	printf("      *      \n");
//
//}
//
// 
// 
// 
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。*/
//int Number_Of_Daffodils(int i) {
//	int j = i;
//	int count1 = 1;
//	int sum = 0;
//	while (j)//统计位数
//	{
//		if (j / 10 != 0) {
//			count1++;
//		}
//		j = j / 10;
//	}
//	j = i;
//	int count2 = count1;
//	while (j)
//	{
//		count1 = count2;
//		int a = 0;
//		a = j % 10;
//		int b = a;
//		j = j / 10;
//		while (count1-1)
//		{
//			a = b * a;
//			count1--;
//		}
//		sum += a;
//	}
//	if (sum == i)
//		return 1;
//	else
//		return 0;
// }
//int main() {
//	int i = 0;
//	for (i = 0; i <= 100000; i++) {
//		if (Number_Of_Daffodils(i))
//			printf("%d ", i);
//	}
//	return 0;
//}
//
// 
//// 求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
//// 例如：2 + 22 + 222 + 2222 + 22222
////答案
//int main()
//{
//	int a = 0;
//	int n = 0;
//	int i = 0;
//	int sum = 0;
//	int tmp = 0;
//
//
//	scanf_s("%d%d", &a, &n);
//	for (i = 0; i < n; i++)
//	{
//		tmp = tmp * 10 + a;
//		sum += tmp;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}
////我的代码
//int main() {
//	int j = 0;
//	int a = 0;
//	scanf_s("%d", &a);
//	int sum = a;
//	for (j = 1; j <= 5; j++) {
//		int b = a;
//		int i = 0;
//		for (i = 1; i <= j; i++) {
//			b = a * 10;
//			sum += b;
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}