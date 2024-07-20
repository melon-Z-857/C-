#include"BinaryTree.h"

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi) {
	if (*pi < n - 1) {
		if (a[*pi] == '#') {
			(*pi)++;
			return NULL;
		}
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		if (root == NULL) {
			perror("BinaryTreeCreate::malloc");
			return NULL;
		}
		root->_data = a[(*pi)++];
		root->_left = BinaryTreeCreate(a, n, pi);
		root->_right = BinaryTreeCreate(a, n, pi);
		return root;
	}
	else {
		return NULL;
	}
}

void BinaryTreeDestory(BTNode** root) {
	assert(root!=NULL);
	if (*root == NULL) {
		return;
	}
	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));
	free(*root);
}

int BinaryTreeSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	int left = BinaryTreeSize(root->_left);
	int right = BinaryTreeSize(root->_right);
	return left + right + 1;
}

int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL) {
		return 1;
	}
	int left = BinaryTreeLeafSize(root->_left);
	int right = BinaryTreeLeafSize(root->_right);
	return left + right;
}

int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	int left = BinaryTreeLevelKSize(root->_left,k-1);
	int right = BinaryTreeLevelKSize(root->_right,k-1);
	return left + right;
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	if (root == NULL) {
		return NULL;
	}
	if (root->_data == x) {
		return root;
	}
	BTNode* left = BinaryTreeFind(root->_left, x);
	BTNode* right = BinaryTreeFind(root->_right, x);
	return left == NULL ? right : left;
}

void BinaryTreePrevOrder(BTNode* root) {
	if (root == NULL) {
		return ;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

#include"Queue.h"

void BinaryTreeLevelOrder(BTNode* root) {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (QueueEmpty(&q) == 0) {
		BTNode* front = QueueFront(&q);
		printf("%c ", front->_data);
		QueuePop(&q);
		if (front->_left != NULL) {
			QueuePush(&q, front->_left);
		}
		if (front->_right != NULL) {
			QueuePush(&q, front->_right);
		}
	}
	QueueDestroy(&q);
}

int BinaryTreeComplete(BTNode* root) {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (QueueEmpty(&q) == 0) {
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL) {
			break;
		}
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}
	while (QueueEmpty(&q) == 0) {
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL) {
			return 0;
		}
	}
	QueueDestroy(&q);
	return 1;
}

int BinaryTreeHigh(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	int left = treeHigh(root->_left);
	int right = treeHigh(root->_right);
	return left > right ? left + 1 : right + 1;
}