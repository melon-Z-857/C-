#include"Heap.h"

void Swap(HPDataType* a, HPDataType* b) {
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

void HeapInit(Heap* hp) {
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}

void HeapDestory(Heap* hp) {
	assert(hp != NULL);
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}

void AjustUp(HPDataType* a, int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

void HeapPush(Heap* hp, HPDataType x) {
	assert(hp != NULL);
	if (hp->_size == hp->_capacity) {
		HPDataType*tmp = (HPDataType*)realloc(hp->_a,sizeof(HPDataType) * (hp->_capacity == 0 ? 1 : 2 * hp->_capacity));
		if (tmp == NULL) {
			perror("HeapPush::realloc");
			return;
		}
		hp->_capacity = (hp->_capacity == 0 ? 1 : 2 * hp->_capacity);
		hp->_a = tmp;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	AjustUp(hp->_a, hp->_size - 1);
}

void AjustDown(HPDataType* a, int size, int parent) {
	int child = parent * 2 + 1;
	while (child < size) {
		if (child + 1 < size && a[child + 1] < a[child]){
			child++;
		}
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void HeapPop(Heap* hp) {
	assert(hp != NULL);
	assert(hp->_size > 0);
	HPDataType tmp = hp->_a[0];
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = tmp;
	hp->_size--;
	AjustDown(hp->_a, hp->_size, 0);
}

int HeapSize(Heap* hp) {
	assert(hp != NULL);
	return hp->_size;
}

int HeapEmpty(Heap* hp) {
	assert(hp != NULL);
	return hp->_size == 0 ? 1 : 0;
}

void HeapSort(int* a, int n) {
	assert(a != NULL);
	int parent = (n - 1 - 1) / 2;
	while (parent >= 0) {
		AjustDown(a, n, parent--);
	}
	int end = n - 1;
	while (end > 0) {
		Swap(&a[0], &a[end]);
		AjustDown(a, end-1, 0);
		end--;
	}
}

void PrintTopK(int k) {
	int* heap = (int*)malloc(sizeof(int) * k);
	if (heap == NULL) {
		perror("PrintTopK::malloc");
		return;
	}
	const char* file = "data.txt";
	FILE* fin = fopen(file, "r");
	if (fin == NULL) {
		perror("PrintTopK::fopen");
		return;
	}
	for (int i = 0; i < k; i++) {
		fscanf_s(fin, "%d", &heap[i]);
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--) {
		AjustDown(heap, k, i);
	}
	int x = 0;
	while (fscanf_s(fin, "%d", &x) > 0) {
		if (x > heap[0]) {
			Swap(&x, &heap[0]);
			AjustDown(heap, k, 0);
		}
	}
	printf("需要查找值最大的前k个数:");
	for (int i = 0; i < k; i++) {
		printf("%d ", heap[k - 1 - i]);
	}
}