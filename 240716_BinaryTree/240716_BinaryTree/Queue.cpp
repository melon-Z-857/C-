#include"Queue.h"

void QueueInit(Queue* q) {
	q->_front = q->_rear = NULL;
}

void QueuePush(Queue* q, QDataType data) {
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	assert(newnode);
	newnode->_data = data;
	newnode->_next = NULL;
	if (q->_rear == NULL) {
		q->_front = q->_rear = newnode;
	}
	else {
		q->_rear->_next = newnode;
		q->_rear = newnode;
	}
}

void QueuePop(Queue* q) {
	assert(q);
	assert(q->_front);
	QNode* del = q->_front;
	QNode* next = del->_next;
	q->_front = next;
	if (del == q->_rear) {
		q->_rear = NULL;
	}
	free(del);
}

QDataType QueueFront(Queue* q) {
	assert(q);
	assert(q->_front);
	return q->_front->_data;
}

QDataType QueueBack(Queue* q) {
	assert(q);
	assert(q->_rear);
	return q->_rear->_data;
}

int QueueSize(Queue* q) {
	assert(q);
	if (q->_front == NULL) {
		return 0;
	}
	int i = 1;
	QNode* pcur = q->_front;
	for (; pcur != q->_rear;) {
		i++;
		pcur = pcur->_next;
	}
	return i;
}

int QueueEmpty(Queue* q) {
	assert(q);
	return q->_rear == NULL ? 1 : 0;
}

void QueueDestroy(Queue* q) {
	QNode* pdel = q->_front;
	for (; pdel != NULL;) {
		QNode* next = pdel->_next;
		free(pdel);
		pdel = next;
	}
}