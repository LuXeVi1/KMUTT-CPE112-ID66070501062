#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize, int* isSuccess) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *isSuccess = 1;
                return result;
            }
        }
    }
    *isSuccess = 0;
    return result;
}

int main() {
    int nums[10] = {1, 2, 3, 4, 5};
    int target = 0;
    printf("Enter the target: ");
    scanf("%d", &target);
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize, isSuccess;
    int* result = twoSum(nums, numsSize, target, &returnSize, &isSuccess);
    int i;
    if (isSuccess == 1) {
        printf("Indices: %d %d\n", result[0], result[1]);
    } else {
        printf("No two numbers add up to the target\n");
    }
    free(result);
    return 0;
}

// Q; โปรแกรมต้นแบบมีการประกาศตัวแปรแบบ Dynamic และจัดการตัวแปรอยางเหมาะสมหรือไม เพราะเหตุผลใด
// A: ไม่เหมาะสม เพราะในโปรแกรมนี้มีการประกาศตัวแปรแบบ Dynamic แต่ไม่มีการจัดการตัวแปรอย่างเหมาะสม ทำให้เกิดปัญหา memory leak ได้