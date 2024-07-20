#include"Seqlist.h"

void SLInit(SL* ps) {
	ps->arr = (SLDataType*)malloc(sizeof(SLDataType) * INIT_CAPACITY);
	ps->size = 0;
	ps->capacity = INIT_CAPACITY;
}

void SLDestroy(SL* ps) {
	assert(ps->arr != NULL);
	free(ps->arr);
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLPrint(SL* ps) {
	assert(ps->arr != NULL);
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

void SLCheckCapacity(SL* ps) {
	SLDataType* tmp = NULL;
	if (ps->size == ps->capacity) {
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, (2 * ps->capacity) * sizeof(SLDataType));
		if (tmp != NULL) {
			ps->arr = tmp;
			ps->capacity *= 2;
		}
	}
}

void SLPushBack(SL* ps, SLDataType x) {
	SLCheckCapacity(ps);
	ps->arr[ps->size] = x;
	ps->size++;
}

void SLPushFront(SL* ps, SLDataType x) {
	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--) {
		ps->arr[i] = ps->arr[i - 1];//[size]=[size-1],[1]=[0]
	}
	ps->arr[0] = x;
	ps->size++;
}

void SLPopBack(SL* ps) {
	assert(ps->arr != NULL);
	assert(ps->size > 0);
	ps->size--;
}

void SLPopFront(SL* ps) {
	assert(ps->arr != NULL);
	assert(ps->size > 0);
	for (int i = 0; i < ps->size - 1; i++) {
		ps->arr[i] = ps->arr[i + 1];//[0]=[1],[size-2]=[size-1]
	}
	ps->size--;
}

void SLInsert(SL* ps, int pos, SLDataType x) {
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos; i--) {
		ps->arr[i] = ps->arr[i - 1];//[s]=[s-1],[pos+1]=[pos]
	}
	ps->arr[pos] = x;
	ps->size++;
}

void SLErase(SL* ps, int pos) {
	assert(ps->arr != NULL);
	assert(ps->size > 0);
	assert(pos >= 0 && pos <= ps->size - 1);
	for (int i = 0; i < ps->size - pos - 1; i++) {
		ps->arr[i + pos] = ps->arr[i + pos + 1];//[pos]=[pos+1],[s-2]=[s-1]
	}
	ps->size--;
}

//int SLFind(SL* ps, SLDataType x) {
//	assert(ps->arr != NULL);
//	assert(ps->size > 0);
//	int flag = 0;
//	for (int i = 0; i < ps->size; i++) {
//		if (ps->arr[i] == x) {
//			return i;
//		}
//	}
//	return -1;
//}