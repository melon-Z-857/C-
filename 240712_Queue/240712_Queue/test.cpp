#include"Queue.h"

int main() {
	Queue q;
	QueueInit(&q);
	QueueEmpty(&q);
	QueuePush(&q, 0);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueueEmpty(&q);
	QueueFront(&q);
	QueueSize(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueueDestroy(&q);
	
	return 0;
}