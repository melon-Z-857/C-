#include"Stack.h"

void StackInit(Stack* ps) {
	ps->_a = (STDataType*)malloc(sizeof(STDataType));
	ps->_capacity = 1;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType data) {
	assert(ps);
	if (ps->_capacity == ps->_top) {
		STDataType* tmp = (STDataType*)realloc(ps->_a, sizeof(STDataType) * ps->_capacity * 2);
		assert(tmp);
		ps->_a = tmp;
		ps->_capacity *= 2;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}

void StackPop(Stack* ps) {
	assert(ps);
	assert(ps->_top > 0);
	ps->_top--;
}

STDataType StackTop(Stack* ps) {
	assert(ps);
	assert(ps->_top > 0);
	return ps->_a[ps->_top - 1];
}

int StackSize(Stack* ps) {
	assert(ps);
	return ps->_top;
}

int StackEmpty(Stack* ps) {
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

void StackDestroy(Stack* ps) {
	free(ps->_a);
	ps->_capacity = 0;
	ps->_top = 0;
}