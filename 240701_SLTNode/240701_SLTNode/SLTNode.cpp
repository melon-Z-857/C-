#include"SLTNode.h"

SLTNode* SLTBuyNode(SLTDataType x) {
	SLTNode* tmp=(SLTNode*)malloc(sizeof(x));
	if (tmp != NULL) {
		SLTNode* newnode = tmp;
		newnode->data = x;
		newnode->next = NULL;
		return newnode;
	}
}

void SLTPrint(SLTNode* phead) {
	SLTNode* pcur = phead;
	for (; pcur != NULL; pcur = pcur->next) {
		printf("%d->", pcur->data);
	}
	printf("\n");
}

void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		SLTNode* pcur = *pphead;
		for (; pcur->next != NULL; pcur = pcur->next);
		pcur->next = newnode;
	}
}

void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopBack(SLTNode** pphead) {
	assert(*pphead != NULL);
	SLTNode* pcur = *pphead; 
	if (pcur->next == NULL) {//只有一个节点
		free(pcur);
		*pphead = NULL;
	}
	else {//有多个节点，pcur为要删除的节点的前一个节点
		for (; pcur->next->next != NULL; pcur = pcur->next);
		free(pcur->next);
		pcur->next = NULL;
	}
}

void SLTPopFront(SLTNode** pphead) {
	assert(*pphead != NULL);
	SLTNode* tmp = *pphead;
	*pphead = (*pphead)->next;
	free(tmp);
	tmp = NULL;
}

SLTNode* SLTFind(SLTNode* phead, SLTDataType x) {
	SLTNode* pcur = phead;
	for (; pcur != NULL; pcur = pcur->next) {
		if (pcur->data == x) {
			return pcur;
		}
	}
	return NULL;
}

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {//如果为空表则直接插入表中，不为空表则必须插入符合的指定的位置
	assert(pphead != NULL);
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else if (*pphead != NULL && pos != NULL) {
		if (pos == *pphead) {//如果在头节点前插入，则需要改变头节点
			newnode->next = pos;
			*pphead = newnode;
		}
		else {
			SLTNode* pcur = *pphead;
			for (; pcur->next != pos && pcur->next != NULL; pcur = pcur->next);
			if (pcur->next == pos) {
				newnode->next = pos;
				pcur->next = newnode;
			}
		}
	}
}

void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(pphead != NULL && pos != NULL);
	if (pos == *pphead) {//删除头节点
		*pphead = (*pphead)->next;
		free(pos);
		pos = NULL;
	}
	else {
		SLTNode* pcur = *pphead;
		for (; pcur->next != NULL && pcur->next != pos; pcur = pcur->next);
		if (pcur->next == pos) {
			pcur->next = pcur->next->next;
			free(pos);
			pos = NULL;
		}
	}
}

void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos != NULL);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLTEraseAfter(SLTNode* pos) {
	assert(pos->next != NULL);
	SLTNode* tmp = pos->next;
	pos->next = pos->next->next;
	free(tmp);
	tmp = NULL;
}

void SListDesTroy(SLTNode** pphead) {
	SLTNode* pdel = *pphead;
	SLTNode* pnextdel = NULL;
	for (; pdel != NULL; pdel = pnextdel) {
		pnextdel = pdel->next;
		free(pdel);
	}
	pdel = NULL;
	pnextdel = NULL;
	*pphead = NULL;
	pphead = NULL;
}