#include"Heap.h"

void test01() {
	Heap hp;
	HeapInit(&hp);

	HeapPush(&hp, 2);
	HeapPush(&hp, 4);
	HeapPush(&hp, 1);
	HeapPush(&hp, 3);
	HeapPush(&hp, 0);

	HeapPop(&hp);
}

void test02() {
	int a[] = { 3,65,77,12,2,43,98,55 };

	//a[]排降序，先从最后一个父节点(n-1)/2的位置到根节点的位置向下调整成小堆，此时根节点就是最小的数，
	// 然后把根节点和最后一个节点交换位置，伪删除最后一个节点，再向下调整成小堆找出次小的数...
	HeapSort(a, sizeof(a) / sizeof(a[0]));
}

void CreateNDate()
{
	// 造数据
	int n = 20;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 100;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void test03() {
	CreateNDate();
	printf("请输入需要查找值最大的数的个数k:\n");
	int k;
	scanf_s("%d", &k);
	PrintTopK(k);
}

int main() {
	//test01();

	test02();

	//test03();

	return 0;
}