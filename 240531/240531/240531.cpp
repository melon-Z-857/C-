#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	printf("%d", -11 % 3);
//	return 0;
//}
int main()
{
	int i = 0;
	int max = 0;
	int arr[10] = { 0 };
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	max = arr[0];
	for (i = 1; i < 10; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
		else
			max = max;
	}
	printf("%d", max);
	return 0;
}