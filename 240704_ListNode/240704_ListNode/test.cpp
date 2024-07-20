#include"List.h"

LTNode* plist;

int main() {
	plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPrint(plist);

	//LTPopBack(plist);
	//LTPrint(plist);
	//LTPopBack(plist);
	//LTPrint(plist);
	//LTPopBack(plist);
	//LTPrint(plist); 
	//LTPopBack(plist);
	//LTPrint(plist);
	//LTPopBack(plist);
	//LTPrint(plist);

	//LTPushFront(plist, 0);
	//LTPrint(plist);

	//LTInsert(LTFind(plist, 4), 6);
	//LTInsert(LTFind(plist, 4), 5);
	//LTPrint(plist);

	LTErase(LTFind(plist, 1));
	LTErase(LTFind(plist, 4));
	LTPrint(plist);


	return 0;
}