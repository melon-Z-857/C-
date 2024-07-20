#include"SLTNode.h"

SLTNode* plist = NULL;

void test01() {
	//SLTPushBack(&plist, 0);
	//SLTPushBack(&plist, 1);
	//SLTPushBack(&plist, 2);
	//SLTPrint(plist);

	//SLTPushFront(&plist, 2);
	//SLTPushFront(&plist, 1);
	//SLTPushFront(&plist, 0);
	//SLTPrint(plist);
	//SLTPopBack(&plist);
	//SLTPopBack(&plist);
	//SLTPopBack(&plist);
	////SLTPopBack(&plist);
	//SLTPrint(plist);

	//SLTPushFront(&plist, 2);
	//SLTPushFront(&plist, 1);
	//SLTPushFront(&plist, 0);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPopFront(&plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLTPushFront(&plist, 2);
	//SLTPushFront(&plist, 1);
	//SLTPushFront(&plist, 0);
	//SLTPrint(plist);
	//SLTFind(plist, 1);

	//SLTPushFront(&plist, 2);
	//SLTPushFront(&plist, 1);
	//SLTPushFront(&plist, 0);
	//SLTPrint(plist);
	//SLTInsert(&plist, SLTFind(plist, 2), 3);
	//SLTInsert(&plist, SLTFind(plist, 0), 4);
	//SLTPrint(plist);
	//SLTInsert(&plist, SLTFind(plist,30), 4);
	//SLTPrint(plist);

	//SLTPushFront(&plist, 2);
	//SLTPushFront(&plist, 1);
	//SLTPushFront(&plist, 0);
	//SLTPrint(plist);
	//SLTErase(&plist, SLTFind(plist, 2));
	//SLTPrint(plist);
	//SLTErase(&plist, SLTFind(plist, 2));
	//SLTPrint(plist);

	//SLTPushFront(&plist, 2);
	//SLTPushFront(&plist, 1);
	//SLTPushFront(&plist, 0);
	//SLTPrint(plist);
	//SLTInsertAfter(SLTFind(plist, 2), 3);
	//SLTPrint(plist);
	//SLTInsertAfter(SLTFind(plist, 0), 4);
	//SLTPrint(plist);

	//SLTPushFront(&plist, 2);
	//SLTPushFront(&plist, 1);
	//SLTPushFront(&plist, 0);
	//SLTPrint(plist);
	//SLTEraseAfter(SLTFind(plist, 1));
	//SLTPrint(plist);
	////SLTEraseAfter(SLTFind(plist, 1));
	////SLTPrint(plist);

	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 0);
	SLTPrint(plist);
	SListDesTroy(&plist);
}

int main() {
	test01();

	return 0;
}