#include<stdio.h>

int main() {
	int a = 1;
	char* p = (char*)&a;
	if (*p == 0x00)
		printf("´ó¶Ë´æ´¢");
	else if(*p==0x01)
		printf("Ð¡¶Ë´æ´¢");

	return 0;
}