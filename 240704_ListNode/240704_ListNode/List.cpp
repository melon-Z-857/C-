#include"List.h"

LTNode* LTFind(LTNode* phead, LTDataType x) {
	LTNode* pcur = phead->next;
	for (; pcur != phead;pcur=pcur->next) {
		if (pcur->data == x) {
			return pcur;
		}
	}
	return NULL;
}

LTNode* LTBuyNode(LTDataType x) {
	LTNode* newnode = (LTNode*)malloc(sizeof(LTDataType));
	if (newnode != NULL) {
		newnode->data = x;
		return newnode;
	}
}

LTNode* LTInit() {
	LTNode* head = (LTNode*)malloc(sizeof(LTNode));
	if (head != NULL) {
		head->data = -1;
		head->next = head;
		head->prev = head;
		return head;
	}
}

void LTDestroy(LTNode* phead) {
	LTNode* pcur = phead->next;
	for (; pcur != phead;) {
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	phead = NULL;
}

void LTPrint(LTNode* phead) {
	LTNode* pcur = phead->next;
	for (; pcur != phead;pcur=pcur->next) {
		printf("%d->", pcur->data);
	}
	printf("\n");
}

bool LTEmpty(LTNode* phead) {
	if (phead->next == phead) {
		return true;
	}
	else {
		return false;
	}
}

void LTPushBack(LTNode* phead, LTDataType x) {
	LTNode* newnode = LTBuyNode(x);
	newnode->next = phead;
	newnode->prev = phead->prev;
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
}

void LTPopBack(LTNode* phead) {
	LTNode* del = phead->prev;
	assert(del != NULL);
	del->prev->next = phead;
	phead->prev = del->prev;
	free(del);
}

void LTPushFront(LTNode* phead, LTDataType x) {
	LTNode* newnode = LTBuyNode(x);
	newnode->prev = phead;
	newnode->next = phead->next;
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
}

void LTPopFront(LTNode* phead) {
	LTNode* del = phead->next;
	assert(del != NULL);
	del->prev->next = del->next;
	del->next->prev = phead;
	free(del);
}

void LTInsert(LTNode* pos, LTDataType x) {
	assert(pos != NULL);
	LTNode* newnode = LTBuyNode(x);
	newnode->prev = pos;
	newnode->next = pos->next;
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
}

void LTErase(LTNode* pos) {
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}