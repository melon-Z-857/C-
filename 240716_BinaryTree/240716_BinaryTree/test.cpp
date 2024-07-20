#include"BinaryTree.h"

void test01() {
	char a[] = "ABD##E#H##CF##G#";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, sizeof(a) / sizeof(a[0]) - 1, &i);
	BinaryTreeDestory(&root);
}

void test02() {
	char a[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, (sizeof(a) / sizeof(a[0])) - 1, &i);
	int size = BinaryTreeSize(root);
	printf("%d\n", size);
	BinaryTreeDestory(&root);
}

void test03() {
	char a[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, (sizeof(a) / sizeof(a[0])) - 1, &i);
	int size = BinaryTreeLeafSize(root);
	printf("%d\n", size);
	BinaryTreeDestory(&root);
}

void test04() {
	char a[] = "ABD##E#H##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, (sizeof(a) / sizeof(a[0])) - 1, &i);
	BinaryTreeLevelKSize(root, 1);
	BinaryTreeLevelKSize(root, 2);
	BinaryTreeLevelKSize(root, 3);
	BinaryTreeLevelKSize(root, 4);
}

void test05() {
	char a[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, (sizeof(a) / sizeof(a[0])) - 1, &i);
	BTNode* find = BinaryTreeFind(root, 'A');
	find = BinaryTreeFind(root, 'B');
	find = BinaryTreeFind(root, 'C');
	find = BinaryTreeFind(root, 'D');
}

void test06() {
	char a[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, (sizeof(a) / sizeof(a[0])) - 1, &i);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
}

void test07() {
	char a[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, (sizeof(a) / sizeof(a[0])) - 1, &i);
	BinaryTreeLevelOrder(root);
}

void test08() {
	char a[] = "ABD##E##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, (sizeof(a) / sizeof(a[0])) - 1, &i);
	printf("%d\n", BinaryTreeComplete(root));
}

void test09() {
	char a[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, (sizeof(a) / sizeof(a[0])) - 1, &i);
	printf("%d\n", BinaryTreeHigh(root));
}

int main() {
	//test01();

	//test02();

	//test03();

	//test04();

	//test05();

	//test06();

	//test07();

	//test08();

	test09();

	return 0;
}