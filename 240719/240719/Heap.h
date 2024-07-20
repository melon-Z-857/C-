#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//交换函数
void Swap(HPDataType* a, HPDataType* b);

void HeapInit(Heap* hp);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);

//向上调整
void AjustUp(HPDataType* a, int child);

//向下调整
void AjustDown(HPDataType* a, int size, int parent);

// 对数组进行堆排序
void HeapSort(int* a, int n);

//堆排序求前K个最值
void PrintTopK(int k);