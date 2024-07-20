#include<stdio.h>
#include<assert.h>

////模拟实现strlen
//size_t my_strlen(const char* p1) {
//	size_t count = 0;
//	for (; *p1 != '\0'; p1++) {
//		count++;
//	}
//	return count;
//}
//
//int main() {
//	char ch1[20] = { "abcdef" };
//	printf("%zd\n", my_strlen(ch1));
//
//	return 0;
//}

////模拟实现strcpy
//char* my_strcpy(char* p1, char* p2) {
//	char* ret = p1;
//	for (; *p2 != '\0'; p1++, p2++) {
//		*p1 = *p2;
//	}
//	*p1 = '\0';
//	return ret;
//}
//int main() {
//	char ch1[20] = { "abcdef" };
//	char ch2[20] = { 0 };
//	printf("%s\n", my_strcpy(ch2,ch1));
//
//	return 0;
//}

////模拟实现strcmp
//int my_strcmp(char* p1, char* p2) {
//	for (; *p1 == *p2; p1++, p2++) {
//		if (*p1 =='\0')
//			return 0;
//	}
//	return *p1 - *p2;
//}
//
//int main() {
//	char ch1[20] = { "abcdef" };
//	char ch2[20] = { "abcq" };
//	printf("%d\n", my_strcmp(ch1, ch2));
//
//	return 0;
//}

////模拟实现strcat
//char* my_strcat(char* p1, char* p2) {
//	char* ret = p1;
//	for (; *p1 != '\0'; p1++);
//	for (; *p2 != '\0'; p1++, p2++) {
//		*p1 = *p2;
//	}
//	return ret;
//}
//
//int main() {
//	char ch1[20] = { "abcd" };
//	char ch2[20] = { "efg" };
//	printf("%s\n", my_strcat(ch1, ch2));
//
//	return 0;
//}

////模拟实现strstr
//char* my_strstr(char* p1, char* p2) {
//	assert(p1 && p2);
//	for (; *p1 != '\0'; p1++) {
//		if (*p1 == *p2) {
//			char* p3 = p1;
//			char* p4 = p2;
//			for (; *p3 == *p4;p3++,p4++) {
//				if (*p3 == '\0')
//					return p1;
//			}
//			if (*p4 == '\0')
//				return p1;
//		}
//	}
//}
//
//int main() {
//	char ch1[] = { "abbbcdef" };
//	char ch2[] = { "bbc" };
//	printf("%s\n", my_strstr(ch1, ch2));
//
//	return 0;
//}

////模拟实现strncpy
//char* my_strncpy(char* p1, char* p2,size_t n) {
//	char* ret = p1;
//	int i = 0;
//	for (i = 0; *p2 != '\0' && i < n; p1++, p2++,i++) {
//		*p1 = *p2;
//	}
//	return ret;
//}
//
//int main() {
//	char ch1[] = { "abbbcdef" };
//	char ch2[] = { "bbc" };
//	printf("%s\n", my_strncpy(ch1, ch2,1));
//
//	return 0;
//}

////模拟实现strncat
//char* my_strncat(char* p1, char* p2,size_t n) {
//	char* ret = p1;
//	for (; *p1 != '\0'; p1++);
//	int i = 0;
//	for (; *p2 != '\0'&&i<n; p1++, p2++,i++) {
//		*p1 = *p2;
//	}
//	return ret;
//}
//
//int main() {
//	char ch1[20] = { "abcd" };
//	char ch2[20] = { "efg" };
//	printf("%s\n", my_strncat(ch1, ch2,1));
//
//	return 0;
//}

////模拟实现memcpy
//void* my_memcpy(void* p1, void* p2, size_t n) {
//	void* ret = p1;
//	int i = 0;
//	for (i = 0; i < n; i++) {
//		*(char*)p1 = *(char*)p2;
//		p1 = (char*)p1 + 1;
//		p2 = (char*)p2 + 1;
//	}
//	return ret;
//}
//
//int main() {
//	int arr1[20] = { 0 };
//	int arr2[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	my_memcpy(arr1, arr2, 16);
//
//	return 0;
//}

////模拟实现memmove
//void* my_memmove(void* p1, void* p2, size_t n) {
//	void* ret = p1;
//	if (p1 < p2) {
//		size_t i = 0;
//		for (i = 0; i < n; i++) {
//			*(char*)p1 = *(char*)p2;
//			p1 = (char*)p1 + 1;
//			p2 = (char*)p2 + 1;
//		}
//	}
//	else {
//		int i = n - 1;
//		for (i = n - 1; i >= 0; i--) {
//			*((char*)p1 + i) = *((char*)p2 + i);
//		}
//	}
//	return ret;
//}
//
//int main() {
//	int arr1[7] = { 1,2,3,4,5,6,7 };
//	my_memmove(arr1 + 2, arr1, 20);
//
//	return 0;
//}

int main() {


	return 0;
}