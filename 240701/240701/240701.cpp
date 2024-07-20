#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
//int removeElement(int* nums, int numsSize, int val) {
//    int k = 0;
//    int i = 0;
//    for (i = 0; i < numsSize; i++) {
//        if (nums[i] == val) {
//            k++;
//            int j = 0;
//            for (j = i; j < numsSize - 1; j++) {
//                nums[j] = nums[j + 1];
//
//            }
//            numsSize--;
//            i--;
//        }
//    }
//    return k;
//}
//
//int main() {
//    int arr[] = { 0,1,2,2,3,0,4,2 };
//    printf("%d\n", removeElement(arr, sizeof(arr)/sizeof(arr[0]), 2));
//
//	return 0;
//}

struct ListNode {
	int val;
	struct ListNode* next;

};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* pcur = head;
    if (pcur->next == NULL) {
        return pcur;
    }
    else {
        struct ListNode* ret = reverseList(pcur->next);
        struct ListNode* tmp1 = pcur;
        struct ListNode* tmp2 = pcur->next;
        tmp2->next = pcur;
        tmp1->next = NULL;
        return ret;
    }
}

int main() {
    

	return 0;
}