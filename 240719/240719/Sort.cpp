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

}