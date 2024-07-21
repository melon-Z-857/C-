#include"Sort.h"

int a[] = { 2,4,1,7,8,5,3,9,6 };

void MyPrintf(int* a, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void test01() {
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
}

void test02() {
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
}

void test03() {
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
}

void test04() {
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
}

void test05() {
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
}

void test06() {
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
	PartSort1(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
}

void test07() {
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
	PartSort2(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
}

void test08() {
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
	PartSort3(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
}

void test09() {
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
}

void test010() {
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
	QuickSortNonR(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
}

void test11() {
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
}

void test12() {
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
	CountSort(a, sizeof(a) / sizeof(a[0]));
	MyPrintf(a, sizeof(a) / sizeof(a[0]));
}

int main() {
	//test01();

	//test02();

	//test03();

	//test04();

	//test05();

	//test06();

	//test07();

	//test08();

	//test09();

	//test010();

	//test11();

	test12();

	return 0;
}