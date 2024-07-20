#include"Stack.h"

int main() {
	Stack stack;
	StackInit(&stack);
	StackEmpty(&stack);
	StackPush(&stack, 0);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackTop(&stack);
	StackSize(&stack);
	StackEmpty(&stack);
	StackEmpty(&stack);
	StackPop(&stack);
	StackPop(&stack);
	StackPop(&stack);
	StackPop(&stack);
	StackPush(&stack, 0);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackDestroy(&stack);
	
	return 0;
}