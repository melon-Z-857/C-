#include"Sort.h"

void InsertSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) {
			if (tmp < a[end]) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n) {
	int gap = n;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int j = 0; j < gap; j++) {
			for (int i = j; i < n - gap; i += gap) {
				int end = i;
				int tmp = a[end + gap];
				while (end >= 0) {
					if (tmp < a[end]) {
						a[end + gap] = a[end];
						end -= gap;
					}
					else {
						break;
					}
				}
				a[end + gap] = tmp;
			}
		}
	}
}

void SelectSort(int* a, int n) {
	for (int begini = 0; begini < n - 1; begini++) {
		int mini = begini;
		for (int i = begini; i < n; i++) {
			if (a[mini] > a[i]) {
				mini = i;
			}
		}
		Swap(&a[mini], &a[begini]);
	}
}

void BubbleSort(int* a, int n) {
	for (int endi = n - 1; endi > 0; endi--) {
		for (int i = 0; i + 1 <= endi; i++) {
			if (a[i] > a[i + 1]) {
				Swap(&a[i], &a[i + 1]);
			}
		}
	}
}

int PartSort1(int* a, int left, int right) {
	if (left >= right) {
		return left;
	}
	int keyi = left;
	int begini = left;
	int endi = right;
	while (begini < endi) {
		while (begini < endi && a[endi] >= a[keyi]) {
			endi--;
		}
		while (begini < endi && a[begini] <= a[keyi]) {
			begini++;
		}
		Swap(&a[begini], &a[endi]);
	}
	Swap(&a[begini], &a[keyi]);
	keyi = begini;
	PartSort1(a, left, keyi - 1);
	PartSort1(a, keyi + 1, right);
}

int PartSort2(int* a, int left, int right) {
	if (left >= right) {
		return left;
	}
	int key = a[left];
	int keyi = left;
	int begini = left;
	int endi = right;
	while (begini < endi) {
		while (begini < endi && a[endi] >= key) {
			endi--;
		}
		Swap(&a[endi], &a[keyi]);
		keyi = endi;
		while (begini < endi && a[begini] <= key) {
			begini++;
		}
		Swap(&a[begini], &a[keyi]);
		keyi = begini;
	}
	Swap(&key, &a[keyi]);
	keyi = begini;
	PartSort2(a, left, keyi - 1);
	PartSort2(a, keyi + 1, right);
}

int PartSort3(int* a, int left, int right) {
	if (left >= right) {
		return left;
	}
	int key = a[left];
	int keyi = left;
	int fronti = left;
	int backi = left+1;
	while (backi <= right) {
		while (backi <= right && a[backi] >= key) {
			backi++;
		}
		if (backi > right) {
			break;
		}
		fronti++;
		Swap(&a[fronti], &a[backi]);
		backi++;
	}
	Swap(&a[left], &a[fronti]);
	keyi = fronti;
	PartSort3(a, left, keyi - 1);
	PartSort3(a, keyi + 1, right);
}

int FindMid(int* a, int left, int right) {
	int mid = left + right / 2;
	if (a[left] <= a[mid] && a[left] >= a[right]) {
		return left;
	}
	if (a[left] <= a[right] && a[left] >= a[mid]) {
		return left;
	}
	if (a[mid] <= a[right] && a[mid] >= a[left]) {
		return mid;
	}
	if (a[mid] <= a[left] && a[mid] >= a[right]) {
		return mid;
	}
	if (a[right] <= a[left] && a[right] >= a[mid]) {
		return right;
	}
	if (a[right] <= a[mid] && a[right] >= a[left]) {
		return right;
	}
}

void QuickSort(int* a, int left, int right) {
	if (left >= right) {
		return;
	}
	if ((right - left) <= 5) {
		InsertSort(&a[left], ((right - left) + 1));
		return;
	}
	int mid = FindMid(a, left, right);
	int keyi = mid;
	int begini = left;
	int endi = right;
	while (begini < endi) {
		while (begini < endi && a[endi] >= a[keyi]) {
			endi--;
		}
		while (begini < endi && a[begini] <= a[keyi]) {
			begini++;
		}
		Swap(&a[begini], &a[endi]);
	}
	Swap(&a[begini], &a[keyi]);
	keyi = begini;
	PartSort1(a, left, keyi - 1);
	PartSort1(a, keyi + 1, right);
}

#include"Stack.h"

void QuickSortNonR(int* a, int left, int right) {
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (!StackEmpty(&st)) {
		int begini = StackTop(&st);
		StackPop(&st);
		int endi = StackTop(&st);
		StackPop(&st);
		int keyi = PartSort3(a, begini, endi);
		if (keyi + 1 < right) {
			StackPush(&st, endi);
			StackPush(&st, keyi + 1);
		}
		if (begini < keyi - 1) {
			StackPush(&st, keyi - 1);
			StackPush(&st, begini);
		}
	}
}

void _MergeSort(int* a, int* tmp, int left, int right) {
	if (left >= right) {
		return;
	}
	int mid = (left + right) / 2;
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);
	int begin1 = left;
	int begin2 = mid + 1;
	int end1 = mid;
	int end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] < a[begin2]) {
			tmp[i++] = a[begin1++];
		}
		else {
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1) {
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2) {
		tmp[i++] = a[begin2++];
	}
	memcpy(&a[left], &tmp[left], sizeof(int) * (right - left + 1));
}

void MergeSort(int* a, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a,tmp, 0, n - 1);
	memcpy(a, tmp, sizeof(int) * n);
}

void CountSort(int* a, int n) {
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
		if (min > a[i]) {
			min = a[i];
		}
	}
	int gap = max - min;
	int* tmp = (int*)malloc(sizeof(int) * (gap + 1));
	for (int i = 0; i < gap + 1; i++) {
		tmp[i] = 0;
	}
	for (int i = 0; i < gap + 1; i++) {
		tmp[a[i] - min]++;
	}
	for (int i = 0; i < n; i++) {
		while (tmp[i] != 0) {
			a[i] = i + min;
			tmp[i]--;
		}
	}
}