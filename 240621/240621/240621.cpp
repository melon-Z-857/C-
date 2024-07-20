#include<stdio.h>
#include<stdlib.h>

////练习使用库函数，qsort排序各种类型的数据
//int cmp_int(const void* p1, const void* p2) {
//	return *(int*)p1 - *(int*)p2;
//}
//
//int cmp_char(const void* p1, const void* p2) {
//	return *(char*)p1 - *(char*)p2;
//}
//
//void print_arr(const void* p, int sz) {
//	int i = 0;
//	for (i = 0; i < sz; i++) {
//		printf("%d ", *((int*)p + i));
//	}
//	printf("\n");
//}
//
//void print_char(const void* p, int sz) {
//	int i = 0;
//	for (i = 0; i < sz; i++) {
//		printf("%c ", *((char*)p + i));
//	}
//	printf("\n");
//}
//
//int main() {
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	char ch[] = { 'f','e','d','c','b','a' };
//	int sz1 = sizeof(arr) / sizeof(arr[0]);
//	int sz2 = sizeof(ch) / sizeof(ch[0]);
//	qsort(arr, sz1, sizeof(arr[0]), cmp_int);
//	qsort(ch, sz2, sizeof(ch[0]), cmp_char);
//	print_arr(arr, sz1);
//	print_char(ch, sz2);
//
//	return 0;
//}


////模仿qsort的功能实现一个通用的冒泡排序
//struct stu
//{
//	char name[20];
//	int age = 0;
//};
//
//void Swap(const void* p1, const void* p2, size_t width) {
//	int i = 0;
//	for (i = 0; i < width; i++) {
//		char tmp = *((char*)p1 + i);
//		*((char*)p1 + i) = *((char*)p2 + i);
//		*((char*)p2 + i) = tmp;
//	}
//}
//
//int cmp_int(const void* p1, const void* p2) {
//	return *(int*)p1 - *(int*)p2;
//}
//int cmp_char(const void* p1, const void* p2) {
//	return *(char*)p1 - *(char*)p2;
//}
//int cmp_name(const void* p1, const void* p2) {
//	return ((struct stu*)p1)->name - ((struct stu*)p2)->name;
//}
//int cmp_age(const void* p1, const void* p2) {
//	return ((struct stu*)p1)->age - ((struct stu*)p2)->age;
//}
//
//void My_bubble_sort(const void* base, size_t n, size_t width, int (*cmp)(const void* p1, const void* p2)) {
//	int i = 0;
//	for (i = 0; i < n - 1; i++) {
//		int j = 0;
//		for (j = 0; j < n - i - 1; j++) {
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//int main() {
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	char ch[] = { 'f','e','d','c','b','a' };
//	struct stu s[3] = { {"zs",35},{"ls",24},{"ww",18} };
//	int sz1 = sizeof(arr) / sizeof(arr[0]);
//	int sz2 = sizeof(ch) / sizeof(ch[0]);
//	int sz3 = sizeof(s) / sizeof(s[0]);
//	My_bubble_sort(arr, sz1, sizeof(arr[0]),cmp_int);
//	My_bubble_sort(ch, sz2, sizeof(ch[0]),cmp_char);
//	My_bubble_sort(s, sz3, sizeof(s[0]), cmp_name);
//	My_bubble_sort(s, sz3, sizeof(s[0]), cmp_age);
//
//	return 0;
//}


